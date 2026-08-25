/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:26:38 by gisidro-          #+#    #+#             */
/*   Updated: 2026/05/25 23:29:13 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include "libft.h"

typedef struct s_garbage_collector
{
	t_list	*head;
}	t_gc;

void	*gc_alloc(size_t size);
void	gc_free(void *ptr);
void	gc_free_array(int n, void **ptr_array);
void	gc_free_all(void);

char	*gc_itoa(int n);
char	*gc_next_line(int fd, int free_static);
char	**gc_split(char const *s, char c, int *n);
char	*gc_strdup(const char *s1);
char	*gc_strjoin(char const *s1, char const *s2);
char	*gc_strjoin_gnl(char *s1, char *s2);
char	*gc_substr(char const *s, unsigned int start, size_t len);
void	*gc_calloc(size_t count, size_t size);
char	*gc_strndup(char *s, int n);
char	*gc_strtrim(char const *s1, char const *set);
t_list	*gc_lstnew(void *content);

#endif