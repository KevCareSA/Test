#include "main.h"

/**
 * handle_C_sig - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void handle_C_sig(int __attribute__((unused))sig)
{
	char *pmt = "\n$ ";

	display_out(pmt);
	signal(SIGINT, handle_C_sig);
}
