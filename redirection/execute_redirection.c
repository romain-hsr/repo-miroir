/*
** EPITECH PROJECT, 2025
** execute_redirection.c
** File description:
** redirect results to files
*/

#include "../include/mini_shell.h"

static int is_append_token(char *token)
{
    return strcmp(token, ">>") == 0;
}

static int is_overwrite_token(char *token)
{
    return strcmp(token, ">") == 0;
}

static void report_error(char **tokens, const char *msg)
{
    mini_printf("%s\n", msg);
    free_tab(tokens);
}

static int validate_next_token(RedirectionContext_t *ctx, int i,
    const char *error_msg)
{
    if (ctx->tokens[i + 1]) {
        ctx->file = ctx->tokens[i + 1];
        ctx->tokens[i] = NULL;
        return 1;
    }
    report_error(ctx->tokens, error_msg);
    return 0;
}

static int process_redirection_token(RedirectionContext_t *ctx, int i)
{
    if (is_append_token(ctx->tokens[i])) {
        ctx->append = 1;
        return validate_next_token(ctx, i,
            "Error: No file specified for append redirection.");
    }
    if (is_overwrite_token(ctx->tokens[i])) {
        ctx->append = 0;
        return validate_next_token(ctx, i,
            "Error: No file specified for redirection.");
    }
    if (ctx->command == NULL)
        ctx->command = ctx->tokens[i];
    return 1;
}

int parse_tokens(RedirectionContext_t *ctx)
{
    for (int i = 0; ctx->tokens[i] != NULL; i++)
        if (!process_redirection_token(ctx, i))
            return 0;
    if (!ctx->command || !ctx->file) {
        report_error(ctx->tokens,
            "Error: Missing command or file.");
        return 0;
    }
    return 1;
}

int open_file(char *file, int append)
{
    int flags = O_WRONLY | O_CREAT | (append ? O_APPEND : O_TRUNC);

    return open(file, flags, 0644);
}

void child_redirect(RedirectionContext_t *ctx)
{
    int fd = open_file(ctx->file, ctx->append);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    execvp(ctx->command, ctx->tokens);
    perror("execvp");
    exit(EXIT_FAILURE);
}

void execute_redirection(char *input, char **env)
{
    RedirectionContext_t ctx = {
        .command = NULL,
        .file = NULL,
        .append = 0
    };
    pid_t pid;

    if (!parse_tokens(&ctx))
        return;
    pid = fork();
    if (pid == 0) {
        child_redirect(&ctx);
    } else if (pid > 0) {
        wait(NULL);
    } else
        perror("fork");
    free_tab(ctx.tokens);
}
