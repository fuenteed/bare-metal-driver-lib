typedef void(*functionPointerType)(void);
struct commandStruct {
	char const *name;
	functionPointerType execute;
	char const *help;
};
