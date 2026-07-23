#ifndef KOREADER_JS_BRIDGE_H
#define KOREADER_JS_BRIDGE_H

#ifdef __cplusplus
extern "C" {
#endif

/* Engine */

int koreader_js_init(void);
void koreader_js_shutdown(void);

/* Execute JavaScript */

int koreader_js_eval(const char *code);

/* Information */

const char *koreader_js_version(void);

#ifdef __cplusplus
}
#endif

#endif
