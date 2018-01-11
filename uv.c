#include <stdio.h>

#define MAX_USER 1024
#define MAX_PASS MAX_USER

#define ERR_CRITIC 0x01
#define ERR_AUTH   0x02

int do_auth()
{
	char username[MAX_USER], password[MAX_PASS];

	fprintf(stdout, "Please enter your username: ");
	fgets(username, MAX_USER, stdin);

	// Using fflush(stdin)
	// https://stackoverflow.com/questions/2979209/using-fflushstdin
	//
	// How to clear stdin before getting new input?
	// https://stackoverflow.com/questions/36715002/how-to-clear-stdin-before-getting-new-input
	fflush(stdin);

	fprintf(stdout, "Please enter your password: ");
	fgets(password, MAX_PASS, stdin);

#ifdef DEBUG
	fprintf(stderr, "Username is at: 0x%8x (%d)\n", &username, strlen(username));
	fprintf(stderr, "Password is at: 0x%8x (%d)\n", &password, strlen(password));
#endif
	
	if (!strcmp(username, "user\n") && !strcmp(password, "washere\n"))
	{
		return 0;
	}

	return -1;
}

int log_error(int farray, char *msg)
{
	char *mesg;
	char buffer[24];

#ifdef DEBUG
	fprintf(stderr, "Mesg is at: 0x%8x\n", &mesg);
	fprintf(stderr, "Mesg is pointing at: 0x%08x\n", mesg);
#endif
	memset(buffer, 0x00, sizeof(buffer));
	sprintf(buffer, "Error: %s", mesg);

	fprintf(stdout, "%s\n", buffer);
	return 0;
}

int main()
{
	switch (do_auth())
	{
	case -1:
		log_error(ERR_CRITIC | ERR_AUTH, "Unable to login");
		break;
	default:
		break;
	}
	return 0;
}
