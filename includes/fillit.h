/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <dshala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:55:39 by dshala            #+#    #+#             */
/*   Updated: 2019/11/15 02:38:37 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct		s_fil
{
	int				block_y[4];
	int				block_x[4];
	struct s_fil	*next;
	int				x_offset;
	int				y_offset;
	char			latter;
}					t_fil;

void				record_position(t_fil *cpy, char buf[], ssize_t read_bytes);
int					read_file(char buf[], int fd, t_fil **head);
int					display_error(void);
int					check_nline_position(char buf[], ssize_t i, ssize_t b);
int					get_valid_string(char buf[], int read_bytes);
int					get_valid_tetramino(char buf[], ssize_t i);
void				create_list(t_fil **head, char buf[], char latter,
					ssize_t read_bytes);
void				align_tetramine(t_fil *list);
void				pushback(t_fil **head, t_fil *new);
void				lstclr(t_fil *head);
int					lstcount(t_fil *head);
char				**get_map(int size);
int					get_size_of_map(t_fil *head);
void				print_map(char **map, int size);
void				delete_map(char **map, int size);
void				get_least_square(t_fil *head);
int					solve_map(t_fil *list, int size, char **map);
void				fill_map(t_fil *lst, char **map, char ch);
int					check_overlap(t_fil *lst, char **map);
int					check_boundaries(int size, t_fil *lst, char ch);

#endif
