#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	CreateRamp({ 0,0,0 }, { 10,1,20 }, 20, {0,0,1}, Blue);
	CreateCubeMap({ 0,0,0 }, { 10,1,20 }, Blue);
	//App->audio->PlayMusic("Assets/BgMusic.ogg",0.0f);
	CreateMap();
	CreateWall();
	int uwu = rand() % 2;
	if(uwu == 0) App->audio->PlayMusic("Assets/Bg6.ogg", 0.0f);
	if(uwu == 1) App->audio->PlayMusic("Assets/Bg8.ogg", 0.0f);
	LOG("%d",uwu);

	

	

	/*physs.PushBack(bodyA);*/

	//physs.PushBack(bodyA);
	//physs.PushBack(bodyB);

	//aaaaaaaaaaaa
	CreateCubeMap({ 113.5,5.5,69 }, { 1,10,1 }, White);
	CreateCubeMap({ 113.5,5.5,71 }, { 1,10,1 }, White);
	CreateCubeMap({ 112.5,5.5,70 }, { 1,10,3 }, White);
	CreateCubeMap({ 114.5,5.5,70 }, { 1,10,3 }, White);
	CreateCubeMap({ 113.5,0,70 }, { 3,1,3 }, White);
	CreateCubeMap({ 113.5,11,70 }, { 3,1,3 }, White);

	//CreateCubeMap({ 143.5,5.5,69 }, { 1,10,1 }, White);
	//CreateCubeMap({ 143.5,5.5,71 }, { 1,10,1 }, White);
	//CreateCubeMap({ 142.5,5.5,70 }, { 1,10,3 }, White);
	//CreateCubeMap({ 144.5,5.5,70 }, { 1,10,3 }, White);
	//CreateCubeMap({ 143.5,0,70 }, { 3,1,3 }, White);
	//CreateCubeMap({ 143.5,11,70 }, { 3,1,3 }, White);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/

	
	//map.cubo.PushBack(*bodyB);
	for (int i = 0; i < map.cubo.Count(); i++) {
		map.cubo[i].Render();
	}
	
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::CreateMap() {

	bodyA = new Cube(1, 10, 1);
	bodyA->SetPos(113.5, 5, 70);

	bodyB = new Cube(20, 10, 5);
	bodyB->SetPos(130.5, 5, 70);
	
	
	bodyB->color = White;
	PhysBody3D* bodyA2 = App->physics->AddBody(*bodyA, 1);
	PhysBody3D* bodyB2 = App->physics->AddBody(*bodyB, 1);
	
	

	App->physics->AddConstraintHinge(*bodyA2, *bodyB2, vec3(15, 0, 0), vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 1, 0), false);




	/*--------------------BackPack--------------------*/
	CreateCubeMap({ 150,8.6,-154 }, { 10,1,10 }, Blue);
	CreateCubeMap({ 160,8.6,-154 }, { 10,1,10 }, Indigo);
	CreateCubeMap({ 170,8.6,-154 }, { 10,1,10 }, Violet);
	CreateCubeMap({ 190,8.6,-154 }, { 30,1,10 }, Red);
	CreateCubeMap({ 190,8.6,-144 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 190,8.6,-134 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 190,8.6,-124 }, { 30,1,10 }, Green);
	CreateCubeMap({ 190,8.6,-114 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 190,8.6,-104 }, { 30,1,10 },Indigo);
	CreateCubeMap({ 190,8.6,-94 }, { 30,1,10 }, Violet);

	CreateRamp({ 190,9.5,-86 }, { 30,1,10 }, 170, { 1,0,0 }, Red);

	CreateRamp({ 190,3.5,-39 }, { 30,1,40 }, 10, { 1,0,0 }, Orange);

	CreateCubeMap({ 190,0,-15 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 190,0,-5 }, { 30,1,10 }, Green);
	CreateCubeMap({ 190,0,5 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 190,0,15 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 190,0,25 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 190,0,35 }, { 30,1,10 }, Red);
	CreateCubeMap({ 190,0,45 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 190,0,55 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 190,0,65 }, { 30,1,10 }, Green);
	CreateCubeMap({ 190,0,75 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 190,0,85 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 190,0,95 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 190,0,105 }, { 30,1,10 }, Red);
	CreateCubeMap({ 170,0,105 }, { 10,1,10 }, Orange);
	CreateCubeMap({ 160,0,105 }, { 10,1,10 }, Yellow);
	CreateCubeMap({ 150,0,105 }, { 10,1,10 }, Green);
	
	/*--------------------BackPack--------------------*/

	CreateCubeMap({ 70,8.6,-195.5 }, { 30,1,30 }, Red);
	CreateCubeMap({ 70,8.6,-215.5 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 70,8.6,-225.5 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 70,8.6,-235.5 }, { 30,1,10 }, Green);

	CreateCubeMap({ 70,8.6,-255.5 }, { 30,1,30 }, Blue);
	CreateCubeMap({ 90,8.6,-255.5 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ 100,8.6,-255.5 }, { 10,1,30 }, Violet);
	CreateCubeMap({ 110,8.6,-255.5 }, { 10,1,30 }, Red);

	CreateCubeMap({ 130,8.6,-255.5 }, { 30,1,30 }, Orange);
	CreateCubeMap({ 130,8.6,-234.75 }, { 30,1,11.6 }, Yellow);
	CreateCubeMap({ 130,8.6,-224 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,8.6,-214 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,8.6,-204 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 130,8.6,-194 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 130,8.6,-184 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,8.6,-174 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 130,8.6,-164 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 130,8.6,-154 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,8.6,-144 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,8.6,-134 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 130,8.6,-124 }, { 30,1,10 }, Violet);

	CreateRamp({ 130,4.3,-94.5 }, { 30,1,50 }, 10, { 1,0,0 }, Red);

	CreateCubeMap({ 130,0,-65 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 130,0,-55 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 130,0,-45 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,-35 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,-25 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 130,0,-15 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 130,0,-5 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,5 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 130,0,15 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 130,0,25 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,35 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,45 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 130,0,55 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 130,0,65 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,75 }, { 30,1,10 }, Orange);
	CreateCubeMap({ 130,0,85 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ 130,0,95 }, { 30,1,10 }, Green);
	CreateCubeMap({ 130,0,105 }, { 30,1,10 }, Blue);
	CreateCubeMap({ 130,0,115 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ 130,0,125 }, { 30,1,10 }, Violet);
	CreateCubeMap({ 130,0,135 }, { 30,1,10 }, Red);
	CreateCubeMap({ 130,0,155 }, { 30,1,30 }, Orange);

	CreateCubeMap({ 110,0,155 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ 100,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ 90,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 80,0,155 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ 70,0,155 }, { 10,1,30 }, Violet);
	CreateCubeMap({ 60,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ 50,0,155 }, { 10,1,30 }, Orange);
	CreateCubeMap({ 40,0,155 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ 30,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ 20,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 10,0,155 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ 0,0,155 }, { 10,1,30 }, Violet);
	CreateCubeMap({ -10,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ -20,0,155 }, { 10,1,30 }, Orange);
	CreateCubeMap({ -30,0,155 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ -40,0,155 }, { 10,1,30 }, Green);
	CreateCubeMap({ -50,0,155 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -60,0,155 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ -70,0,155 }, { 10,1,30 }, Violet);
	CreateCubeMap({ -80,0,155 }, { 10,1,30 }, Red);
	CreateCubeMap({ -90,0,155 }, { 10,1,30 }, Orange);
	CreateCubeMap({ -100,0,155 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ -120,0,155 }, { 30,1,30 }, Green);

	CreateCubeMap({ -120,0,135 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,0,125 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -120,0,115 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -120,0,105 }, { 30,1,10 }, Red);

	CreateRamp({ -120,4,80 }, { 30,1,50 }, 10, { 1,0,0 }, Orange);

	CreateCubeMap({ -120,8.3,50.5 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ -120,8.3,40.5 }, { 30,1,10 }, Green);
	CreateCubeMap({ -120,8.3,30.5 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,8.3,20.5 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -120,8.3,0.5 }, { 30,1,30 }, Violet);

	CreateRamp({ -81,12.5,0.5 }, { 50,1,30 }, 10, { 0,0,1 }, Red);

	CreateCubeMap({ -51.5,16.8,0.5 }, { 10,1,30 }, Orange);
	CreateCubeMap({ -41.5,16.8,0.5 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ -31.5,16.8,0.5 }, { 10,1,30 }, Green);
	CreateCubeMap({ -11.5,16.8,0.5 }, { 30,1,30 }, Blue);

	CreateCubeMap({ -11.5,16.8,70.5 }, { 30,1,30 }, Indigo);
	CreateCubeMap({ -11.5,16.8,50.5 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -11.5,16.8,40.5 }, { 30,1,10 }, Red);
	CreateCubeMap({ -11.5,16.8,30.5 }, { 30,1,10 }, Orange);
	CreateCubeMap({ -11.5,16.8,20.5 }, { 30,1,10 }, Yellow);

	CreateRamp({ -51,21.2,70.5 }, { 50,1,30 }, 170, { 0,0,1 }, Green);

	CreateCubeMap({ -80.5,25.5,70.5 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -90.5,25.5,70.5 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ -100.3,25.5,70.5 }, { 9.5,1,30 }, Violet);
	CreateCubeMap({ -120,25.5,70.5 }, { 30,1,30 }, Red);

	CreateCubeMap({ -120,25.5,50.5 }, { 30,1,10 }, Orange);
	CreateCubeMap({ -120,25.5,40.5 }, { 30,1,10 }, Yellow);
	CreateCubeMap({ -120,25.5,30.5 }, { 30,1,10 }, Green);
	CreateCubeMap({ -120,25.5,20.5 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,25.5,10.5 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -120,25.5,0.5 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -120,25.5,-9.5 }, { 30,1,10 }, Red);
	CreateCubeMap({ -120,25.5,-19.5 }, { 30,1,10 }, Orange);

	CreateRamp({ -120,21.2,-49 }, { 30,1,50 }, 170, { 1,0,0 }, Yellow);

	CreateCubeMap({ -120,17,-78.2 }, { 30,1,10 }, Green);
	CreateCubeMap({ -120,17,-88.2 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,17,-98.2 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -120,17,-108.2 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -120,17,-118.2 }, { 30,1,10 }, Red);
	CreateCubeMap({ -120,17,-128.2 }, { 30,1,10 }, Orange);
	CreateCubeMap({ -120,17,-138.2 }, { 30,1,10 }, Yellow);

	CreateRamp({ -120,12.7,-167.5 }, { 30,1,50 }, 170, { 1,0,0 }, Green);

	CreateCubeMap({ -120,8.6,-195.5 }, { 30,1,10 }, Blue);
	CreateCubeMap({ -120,8.6,-205.5 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -120,8.6,-215.5 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -120,8.6,-225.5 }, { 30,1,10 }, Red);
	CreateCubeMap({ -120,8.6,-235.5 }, { 30,1,10 }, Orange);
	CreateCubeMap({ -120,8.6,-255.5 }, { 30,1,30 }, Yellow);

	CreateCubeMap({ -30,8.6,-255.5 }, { 10,1,30 }, Green);
	CreateCubeMap({ -40,8.6,-255.5 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ -50,8.6,-255.5 }, { 10,1,30 }, Orange);
	CreateCubeMap({ -60,8.6,-255.5 }, { 10,1,30 }, Red);
	CreateCubeMap({ -70,8.6,-255.5 }, { 10,1,30 }, Violet);
	CreateCubeMap({ -80,8.6,-255.5 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ -90,8.6,-255.5 }, { 10,1,30 }, Blue);
	CreateCubeMap({ -100,8.6,-255.5 }, { 10,1,30 }, Green);

	CreateCubeMap({ -10,8.6,-255.5 }, { 30,1,30 }, Blue);
	CreateCubeMap({ -10,8.6,-235.5 }, { 30,1,10 }, Indigo);
	CreateCubeMap({ -10,8.6,-225.5 }, { 30,1,10 }, Violet);
	CreateCubeMap({ -10,8.6,-215.5 }, { 30,1,10 }, Red);
	CreateCubeMap({ -10,8.6,-195.5 }, { 30,1,30 }, Orange);

	CreateCubeMap({ 10,8.6,-195.5 }, { 10,1,30 }, Yellow);
	CreateCubeMap({ 20,8.6,-195.5 }, { 10,1,30 }, Green);
	CreateCubeMap({ 30,8.6,-195.5 }, { 10,1,30 }, Blue);
	CreateCubeMap({ 40,8.6,-195.5 }, { 10,1,30 }, Indigo);
	CreateCubeMap({ 50,8.6,-195.5 }, { 10,1,30 }, Violet);

	CreateCubeMap({ 148,0,-35 }, { 1,30,1 }, Violet);
	CreateCubeMap({ 113,0,-35 }, { 1,30,1 }, Violet);
	CreateCubeMap({ 130,15,-35 }, { 40,5,1 }, Violet);
}

void ModuleSceneIntro::CreateWall() {
	/*------------------BackPack------------------*/
	//Esquina inferior CreateCubeMap({ 190,8.6,-154 }, { 30,1,10 }, Red);
	CreateCubeMap({ 190,9.6,-159.5 }, { 30,3,1 }, White);
	CreateCubeMap({ 205.5,9.6,-149 }, { 1,3,20 }, White);

	//Esquina superior CreateCubeMap({ 190,0,105 }, { 30,1,10 }, Red);
	CreateCubeMap({ 190,2,110.5 }, { 30,3,1 }, White);
	CreateCubeMap({ 205.5,2,100 }, { 1,3,20 }, White);
	/*------------------BackPack------------------*/
	/*--------------------Feet--------------------*/
	CreateCubeMap({ 130,9.6,-271 }, { 30,3,1 }, White);
	CreateCubeMap({ 145.5,9.6,-255.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -120,9.6,-271 }, { 30,3,1 }, White);
	CreateCubeMap({ -135.5,9.6,-255.5 }, { 1,3,30 }, White);

	CreateCubeMap({ 70,9.6,-271 }, { 30,3,1 }, White);
	CreateCubeMap({ 54.5,9.6,-255.5 }, { 1,3,30 }, White);

	CreateCubeMap({ 70,9.6,-180 }, { 30,3,1 }, White);
	CreateCubeMap({ 85.5,9.6,-195.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -10,9.6,-180 }, { 30,3,1 }, White);
	CreateCubeMap({ -25.5,9.6,-195.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -10,9.6,-271 }, { 30,3,1 }, White);
	CreateCubeMap({ 5.5,9.6,-255.5 }, { 1,3,30 }, White);
	/*--------------------Feet--------------------*/
	/*--------------------Head--------------------*/
	CreateCubeMap({ 130,2,170.5 }, { 30,3,1 }, White);
	CreateCubeMap({ 145.5,2,155 }, { 1,3,30 }, White);

	CreateCubeMap({ -120,2,170.5 }, { 30,3,1 }, White);
	CreateCubeMap({ -135.5,2,155 }, { 1,3,30 }, White);
	/*--------------------Head--------------------*/
	/*--------------------Ramp--------------------*/
	CreateCubeMap({ -120,2,170.5 }, { 30,3,1 }, White);
	CreateCubeMap({ -135.5,2,155 }, { 1,3,30 }, White);

	CreateCubeMap({ -120,9.3,-15 }, { 30,3,1 }, White);
	CreateCubeMap({ -135.5,9.3,0.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -11.5,17.8,-15 }, { 30,3,1 }, White);
	CreateCubeMap({ 4,17.8,0.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -11.5,17.8,86 }, { 30,3,1 }, White);
	CreateCubeMap({ 4,17.8,70.5 }, { 1,3,30 }, White);

	CreateCubeMap({ -120,26.5,86 }, { 30,3,1 }, White);
	CreateCubeMap({ -135.5,26.5,70.5 }, { 1,3,30 }, White);
	/*--------------------Ramp--------------------*/

	//CreateConst({ -18.7, 4, -109.5 }, Blue);
	//CreateConst({ 18.7, 4, -109.5 }, Blue);


	
}

void ModuleSceneIntro::CreateCubeMap(const vec3 pos, const vec3 dim, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	
	a->SetPos(pos.x, pos.y, pos.z);
	map.cubo.PushBack(*a);
	map.cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

void ModuleSceneIntro::CreateRamp(const vec3 pos, const vec3 dim, float angle,const vec3& orient, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	a->SetPos(pos.x, pos.y, pos.z);
	a->SetRotation(angle, orient);
	map.cubo.PushBack(*a);
	map.cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::CreateCheckMap(const vec3 pos, const vec3 dim, Color color) {
	Cube* a;
	a = new Cube(dim.x, dim.y, dim.z);
	a->color = color;
	a->SetPos(pos.x, pos.y, pos.z);
	map.cubo.PushBack(*a);
	//map.cubo3d.PushBack(App->physics->AddBody(*a, 0.0f));
}

//void ModuleSceneIntro::CreateConst(vec3 pos, Color color) {
//	Cube* bodyA;
//	bodyA = new Cube(5, 10, 5);
//	bodyA->SetPos(pos.x, 1.5, pos.z);
//	bodyA->color = color;
//
//	Cube* bodyB;
//	bodyB = new Cube(5, 10, 5);
//	bodyB->SetPos(pos.x, -0.2, pos.z);
//	bodyB->color = color;
//
//	btTransform frameInA;
//	frameInA.getBasis().setEulerZYX(0, 0, M_PI / 2);
//	frameInA.setOrigin(btVector3(0, 0, 0));
//
//	btTransform frameInB;
//	frameInB.getBasis().setEulerZYX(0, 0, M_PI / 2);
//	frameInB.setOrigin(btVector3(0, 0, 0));
//
//	PhysBody3D* bodyA2 = App->physics->AddBody(*bodyA, 1);
//	PhysBody3D* bodyB2 = App->physics->AddBody(*bodyB, 1);
//
//	App->physics->AddConstraintSlider(*bodyA2, *bodyB2, frameInA, frameInB);
//
//	/*Cube* bodyA;
//	bodyA = new Cube(5, 10, 5);
//	bodyA->SetPos(135, 1, 1);
//
//	Cube* bodyB;
//	bodyB = new Cube(5, 10, 5);
//	bodyB->SetPos(130, 1, 1);
//
//	PhysBody3D* bodyA2 = App->physics->AddBody(*bodyA, 1);
//	PhysBody3D* bodyB2 = App->physics->AddBody(*bodyB, 1);
//
//	App->physics->AddConstraintHinge(*bodyA2, *bodyB2, vec3(10, 0, 0), vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 1, 0), false);*/
//	
//}