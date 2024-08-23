#pragma once
#include<string>
class Resource
{
protected:
	//pure abstract class
	   //If you inherit from me, you MUST override some fn
	int counter = 0;


	//only 1 data have
	void* data;
	//Use static cast for this to become Texture*, Audio* .... when needed


	//fn to return the data
	//virtual fn to LOAD data
	//virtual fn to UNLOAD data

public:
	Resource();
	virtual void Load(const std::string& name) = 0;
	virtual void UnLoad() = 0;
	virtual ~Resource();//Otherwise you would Not be deleting the specialized classes

};