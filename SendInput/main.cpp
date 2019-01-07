#include <Windows.h>

void InputKeyValue(int vk, BOOL bExtended)
{
	KEYBDINPUT kb = {0};
	INPUT input = {0};

	if (bExtended) { kb.dwFlags = KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	input.type = INPUT_KEYBOARD;
	input.ki = kb;
	SendInput(1, &input, sizeof(input));

	ZeroMemory(&kb, sizeof(KEYBDINPUT));
	ZeroMemory(&input, sizeof(INPUT));
	kb.dwFlags = KEYEVENTF_KEYUP;
	if (bExtended) { kb.dwFlags |= KEYEVENTF_EXTENDEDKEY; }
	kb.wVk = vk;
	input.type = INPUT_KEYBOARD;
	input.ki = kb;
	SendInput(1, &input, sizeof(input));

	return;
}

int main()
{
	char *str = "Hello, World!\n";

	Sleep(5000);
	InputKeyValue('A', FALSE);
	InputKeyValue('B', FALSE);
	InputKeyValue(VK_CAPITAL, TRUE);
	InputKeyValue('C', FALSE);
	InputKeyValue(VK_CAPITAL, TRUE);
	return 0;
}