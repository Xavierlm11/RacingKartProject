#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------

	car.chassis_size.Set(2.0f, 0.55f, 3.0f);
	car.chassis_offset.Set(0.0f, 0.5f, 0.0f);
	car.rear_wing_size.Set(1.2f, 0.05f, 0.5f);
	car.rear_wing_offset.Set(0.0f, 1.05f, -1.5f);
	car.vertical_wing_size.Set(0.05f, 0.5f, 0.5);
	car.vertical_wing_offset.Set(0.6f, 1.0f, -1.5f);
	car.person_size.Set(0.9f, 1.3f, 0.7f);
	car.person_offset.Set(0.0f, 1.0f, -0.5f);


	car.mass = 1000.0f;
	car.suspensionStiffness = 25.88f;
	car.suspensionCompression = 1.83f;
	car.suspensionDamping = 2.88f;
	car.maxSuspensionTravelCm = 500.0f;
	car.frictionSlip = 30.5f;
	car.maxSuspensionForce = 1500.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float front_wheel_radius = 0.5f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	//float half_width = car.chassis_size.x*0.5f;
	//float half_length = car.chassis_size.z*0.5f;

	float half_width = car.chassis_size.x * 0.6;  // 0.5f
	float front_wheels = (car.chassis_size.z * 1.2) -1.5f;
	float rear_wheels = car.chassis_size.z * 0.6;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, front_wheels - front_wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = front_wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, front_wheels - front_wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = front_wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -rear_wheels + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -rear_wheels + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->surface = (car.chassis_size.x * car.chassis_size.y * car.chassis_size.z) * 0.5;
	vehicle->SetPos(0, 530, -25);
	clock.Start();
	state = 0;
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;
	char title[80];
	vec3 pos = vehicle->GetPos();
	uint miliseconds = clock.Read() % 1000;
	uint seconds = (clock.Read() / 1000) % 60;
	uint minutes = (clock.Read() / 1000) / 60;
	switch (state) {
	case 0:
		sprintf_s(title, "AMONG US RACING GAME SUUUUUUUUS");
		App->window->SetTitle(title);
		if (seconds > 7) {
			Respow();
			state = 1;
			clock.Stop();
			clock.Start();
		}
		break;
	case 1:
		sprintf_s(title, "READY!");
		App->window->SetTitle(title);
		if (seconds > 2) {
			state = 2;
			clock.Stop();
			clock.Start();
		}
		break;
	case 2:
		sprintf_s(title, "STADY!");
		App->window->SetTitle(title);
		if (seconds > 2) {
			state = 3;
			clock.Stop();
			clock.Start();
		}
		break;
	case 3:
		if (minutes == 0 && seconds < 2) {
			sprintf_s(title, "GO!");
			App->window->SetTitle(title);
		}
		else {
			sprintf_s(title, "Time: %02d:%02d:%03d | %.1f Km/h | x: %f, y: %f, z: %f", minutes, seconds, miliseconds, vehicle->GetKmh(), pos.x, pos.y, pos.z);
			App->window->SetTitle(title);
		}
		if (minutes >= 3) {
			state = 5;
			clock.Stop();
		}

		if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		{
			acceleration = MAX_ACCELERATION * 6;
		}
		//else if (vehicle->GetKmh() > 0) acceleration = -2200;

		if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		{
			if (turn < TURN_DEGREES)
				turn += TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		{
			if (turn > -TURN_DEGREES)
				turn -= TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
		{
			//brake = BRAKE_POWER;
			acceleration = BACKING * 6;
		}
		//else if (vehicle->GetKmh() < 0) acceleration = 700;
		{vec3 a = vehicle->GetPos();
		if (App->input->GetKey(SDL_SCANCODE_P) == KEY_REPEAT || a.y < -25)
		{
			Respow();
			//vehicle->body->setAngularVelocity({ 0,0,0 });
			//vehicle->body->setLinearVelocity({ 0,0,0 });
			//mat4x4 rot;
			//vec3 a = (0, 0, 0);
			////rot.rotate(0, a);
			//vehicle->SetTransform(&rot);
			//vehicle->SetPos(0, 2, 0);
		}
		if (App->input->GetKey(SDL_SCANCODE_O) == KEY_REPEAT)
		{
			vehicle->body->setAngularVelocity({ 0,0,0 });
			vehicle->body->setLinearVelocity({ 0,0,0 });
			mat4x4 rot;
			vec3 a = (0, 0, 0);

			vehicle->SetTransform(&rot);
			vehicle->SetPos(130, 500, 55);
			rot.rotate(0, a);
		}
		}
		break;
	case 5:
		sprintf_s(title, "TIME OUT");
		App->window->SetTitle(title);
		if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_REPEAT) {
			state = 0;
		}
		break;
	}
	
	DragForce();
	LiftForce();
	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);
	mat4x4 rot;
	rot.rotate(0, {0,0,0});
	vehicle->Render();



	/*char title[80];
	vec3 pos = vehicle->GetPos();
	uint miliseconds = clock.Read() % 1000;
	uint seconds = (clock.Read() / 1000) % 60;
	uint minutes = (clock.Read() / 1000) / 60;
	sprintf_s(title, "Time: %02d:%02d:%03d | %.1f Km/h | x: %f, y: %f, z: %f", minutes, seconds, miliseconds, vehicle->GetKmh(),pos.x,pos.y,pos.z);
	App->window->SetTitle(title);*/

	return UPDATE_CONTINUE;
}


void ModulePlayer::Respow()
{
	vehicle->body->setAngularVelocity({ 0,0,0 });
	vehicle->body->setLinearVelocity({ 0,0,0 });
	mat4x4 rot;
	vec3 a = (0, 0, 0);
	
	vehicle->SetTransform(&rot);
	vehicle->SetPos(130, 4, 55);
	rot.rotate(0, a);
}

void ModulePlayer::DragForce() {
	float vel = vehicle->GetKmh() * 0.2778; //en m/s
	float speed = vel - atmosphere.wind;
	double fdrag = 0.5 * atmosphere.density * speed * speed * vehicle->surface * vehicle->cd;
	double fd = (-speed) * fdrag;
	acceleration += fd;
}

void ModulePlayer::LiftForce() {
	float vel = vehicle->GetKmh() * 0.2778; //en m/s
	float speed = vel - atmosphere.wind;
	double flift = 0.5 * atmosphere.density * speed * speed * vehicle->surface * vehicle->cl;
	double fl = speed * flift;
	acceleration += fl;
}
