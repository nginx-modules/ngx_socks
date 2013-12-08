/*
	Xin Yang.
	Bug report: xyang.cq@gmail.com
*/

#ifndef _NGX_SOCK_H_INCLUDED_
#define _NGX_SOCK_H_INCLUDED_

#include <ngx_config.h>
#include <ngx_core.h>

typedef struct{
	struct sockaddr_in addr;
}ngx_sock_conf_t;

typedef struct{
	ngx_str_t name;
	void *(*create_conf)(ngx_cycle_t *cycle);
	char *(*init_conf)(ngx_cycle_t *cycle, void *conf);
}ngx_sock_module_t;

#define NGX_SOCK_CONF 0x02000000

static char *ngx_sock_block(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);
static char *ngx_sock_port(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

static void *ngx_sock_module_create_conf(ngx_cycle_t *cycle);
static char * ngx_sock_module_init_conf(ngx_cycle_t *cycle, void *conf);

#endif