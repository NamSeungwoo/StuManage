#include "App.h"
void main()
{
	App *app = App::GetInstance();
	app->Run();
}