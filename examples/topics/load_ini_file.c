/* examples/topics/load_ini_file.c */

#include <stdio.h>
#include <confini.h>

int ini_listener (IniDispatch *dispatch, void *v_null) {

	printf(
		"DATA: %s\nVALUE: %s\nNODE TYPE: %d\n\n",
		dispatch->data, dispatch->value, dispatch->type
	);

	return 0;

}

int main () {

	FILE * const ini_file = fopen("example.conf", "r");

	if (ini_file == NULL) {

		fprintf(stderr, "File doesn't exist :-(\n");
		return 1;

	}

	if (load_ini_file(ini_file, INI_DEFAULT_FORMAT, NULL, ini_listener, NULL)) {

		fprintf(stderr, "Sorry, something went wrong :-(\n");
		return 1;

	}

	fclose(ini_file);

	return 0;

}
