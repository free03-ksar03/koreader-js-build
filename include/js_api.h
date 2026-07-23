#ifndef KOREADER_JS_API_H
#define KOREADER_JS_API_H

#ifdef __cplusplus
extern "C" {
#endif

/* Engine */

int js_init(void);
void js_shutdown(void);

/* Script */

int js_eval(const char *code);
int js_eval_file(const char *filename);

/* Values */

const char *js_get_string(void);
int js_get_int(void);
double js_get_double(void);

/* Errors */

const char *js_last_error(void);

#ifdef __cplusplus
}
#endif

#endif
