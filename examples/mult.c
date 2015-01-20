#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

void
reverse(char* input)
{
	size_t len;

	len = strlen(input);
	for (int i = 0; i < len / 2; ++i) {
		char tmp;

		tmp = input[i];
		input[i] = input[len - 1 - i];
		input[len - 1 - i] = tmp;
	}
}

int
mult(char* input1, char* input2, char* result)
{
	size_t input1_len, input2_len;
	uint8_t input1_value, input2_value, result_value;
	uint8_t prev_value, carry_value;

	reverse(input1);
	reverse(input2);

	input1_len = strlen(input1);
	input2_len = strlen(input2);

	memset(result, '0', input1_len + input2_len);

	for (int i = 0; i < input1_len; ++i) {
		input1_value = input1[i] - '0';
		carry_value = 0;

		for (int j = 0; j < input2_len; ++j) {
			input2_value = input2[j] - '0';
			prev_value = result[i + j] - '0';

			result_value = (input1_value * input2_value) + carry_value + prev_value;
			if (result_value > 9) {
				carry_value = result_value / 10;
				result_value -= carry_value * 10;
			} else {
				carry_value = 0;
			}

			assert(result_value < 10);
			result[i + j] = '0' + result_value;
		}
	}

	if (carry_value > 0) {
		result[input1_len + input2_len - 1] = '0' + carry_value;
		result[input1_len + input2_len] = '\0';
	} else {
		result[input1_len + input2_len - 1] = '\0';
	}

	reverse(input1);
	reverse(input2);
	reverse(result);

	return 0;
}

int
main(int argc, char* argv[])
{
	char input1[] = "20";
	char input2[] = "2";
	char* result = NULL;

	result = (char*) malloc((strlen(input1) + strlen(input2))*
				sizeof(char) + 1);

	mult(input1, input2, result);

	printf("%s\n", result);

	if (result)
		free(result);
	return 0;
}
