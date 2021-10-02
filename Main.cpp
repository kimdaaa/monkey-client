#include "Main.h"


void run()
{
	while (GetAsyncKeyState(VK_END))
	{
		setSprinting(true);
		Sleep(10);
	}
}

jobject getMinecraft()
{
	jclass minecraftClass = mc.env->FindClass("ave");
	jmethodID findMinecraft = mc.env->GetStaticMethodID(minecraftClass, "A", "()Lave;");
	return mc.env->CallStaticObjectMethod(minecraftClass, findMinecraft);
}
jobject getPlayer()
{
	jfieldID getPlayer = mc.env->GetFieldID(mc.env->GetObjectClass(getMinecraft()), "h", "Lbew;");
	return mc.env->GetObjectField(getMinecraft(), getPlayer);
}
void setSprinting(jboolean sprinting)
{
	jmethodID setSprinting = mc.env->GetMethodID(mc.env->GetObjectClass(getPlayer()), "d", "(Z)V");
	mc.env->CallBooleanMethod(getPlayer(), setSprinting, sprinting);
}
