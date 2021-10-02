#pragma once
#include <Windows.h>
#include <iostream>
#include "JNI/jni.h"



class Main
{
public:
	JavaVM* vm;
	JNIEnv* env;
	JavaVMInitArgs vm_args;
} mc ;

void run();

jobject getMinecraft();
jobject getPlayer();
void setSprinting(jboolean sprinting);

