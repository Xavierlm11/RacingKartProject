#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"
#include <time.h>  
// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;
	//srand(time(NULL));
	

	float uwu = rand() % 254;
	float owo = rand() % 254;
	float umu = rand() % 254;

	//wheel.color = Black;
	wheel.color = {umu / 255, uwu / 255, owo / 255, 0.8f };
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[i].radius;
		wheel.height = info.wheels[i].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	//chassis.color = Red;
	chassis.color = { uwu / 255, owo / 255, umu / 255, 0.8f };
	Cube rear_wing(info.rear_wing_size.x, info.rear_wing_size.y, info.rear_wing_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&rear_wing.transform);
	btVector3 rw_offset(info.rear_wing_offset.x, info.rear_wing_offset.y, info.rear_wing_offset.z);
	rw_offset = rw_offset.rotate(q.getAxis(), q.getAngle());
	rear_wing.transform.M[12] += rw_offset.getX();
	rear_wing.transform.M[13] += rw_offset.getY();
	rear_wing.transform.M[14] += rw_offset.getZ();
	rear_wing.color = White;

	Cube right_wing(info.vertical_wing_size.x, info.vertical_wing_size.y, info.vertical_wing_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&right_wing.transform);
	btVector3 vw_offset(info.vertical_wing_offset.x, info.vertical_wing_offset.y, info.vertical_wing_offset.z);
	vw_offset = vw_offset.rotate(q.getAxis(), q.getAngle());
	right_wing.transform.M[12] += vw_offset.getX();
	right_wing.transform.M[13] += vw_offset.getY();
	right_wing.transform.M[14] += vw_offset.getZ();
	right_wing.color = White;

	Cube left_wing = right_wing;
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&left_wing.transform);
	btVector3 lw_offset(-info.vertical_wing_offset.x, info.vertical_wing_offset.y, info.vertical_wing_offset.z);
	lw_offset = lw_offset.rotate(q.getAxis(), q.getAngle());
	left_wing.transform.M[12] += lw_offset.getX();
	left_wing.transform.M[13] += lw_offset.getY();
	left_wing.transform.M[14] += lw_offset.getZ();
	left_wing.color = White;

	Cube person(info.person_size.x, info.person_size.y, info.person_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&person.transform);
	btVector3 u_offset(info.person_offset.x, info.person_offset.y, info.person_offset.z);
	u_offset = u_offset.rotate(q.getAxis(), q.getAngle());
	person.transform.M[12] += u_offset.getX();
	person.transform.M[13] += u_offset.getY();
	person.transform.M[14] += u_offset.getZ();
	//person.color = Carne;
	person.color = { owo / 255, umu / 255, uwu / 255, 0.8f };
	chassis.Render();
	/*bridge.Render();
	front_wing.Render();*/
	rear_wing.Render();
	right_wing.Render();
	left_wing.Render();
	person.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}