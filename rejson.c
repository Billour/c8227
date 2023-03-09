#include <stdio.h>
#include <stdlib.h>
#include "cjson/cJSON.h"

int main() {
	char *json_string = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";	        
	cJSON *json = cJSON_Parse(json_string);

	if (json == NULL) {
		printf("Error parsing JSON string: %s\n", cJSON_GetErrorPtr());
		return 1;
	}
	cJSON *name = cJSON_GetObjectItem(json, "name");
	if (name == NULL) {
		printf("Error getting name from JSON object\n");
		cJSON_Delete(json);
		return 1;
	}

	printf("Name: %s\n", name->valuestring);

	cJSON_Delete(json);
	return 0;
}
