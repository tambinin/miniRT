/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:40:46 by candriam          #+#    #+#             */
/*   Updated: 2025/03/14 23:16:04 by tambinin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "libftprintf.h"
# include "struct.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void		cam_init_axis(t_camera *cam);
void		apply_rot_y(t_camera *cam, float angle);
void		apply_rot_x(t_camera *cam, float angle);
void		process_resizing(int keycode, t_minirt *minirt);
void		handle_tools_two(int keycode, t_minirt *minirt);
void		render_alias(t_minirt *rt);
void		process_render(t_minirt *rt, t_col final_color, int *x, int *y);
void		handle_zoom(int keycode, t_minirt *minirt);
void		handle_cylinder_move(int keycode, t_minirt *minirt);
void		handle_light_move(int keycode, t_minirt *minirt);
void		handle_camera_move(int keycode, t_minirt *minirt);
void		handle_cy_rotation(int keycode, t_minirt *minirt);
void		activate_rotate_axis(int keycode, t_minirt *minirt);
void		handle_plane_rotation(int keycode, t_minirt *minirt);
void		activate_elem_rotation(int keycode, t_minirt *minirt);
void		handle_camera_rotation(int keycode, t_minirt *minirt);
void		mult_mat(float mat1[4][4], float mat2[4][4], float result[4][4]);
void		*safe_malloc(size_t size);
void		init_minirt(t_minirt *rt);
void		exit_error(t_minirt *rt);
void		substitute_to_spaces(char *str, char delimeter);
void		setup_hooks(t_minirt *minirt);
void		handle_tools_one(int keycode, t_minirt *minirt);
void		free_objects(t_minirt *rt);
void		clean_win_display(t_set *set);
void		clean_minirt_struct(t_minirt *minirt);
void		clean_resources(t_minirt *minirt);
void		clean_minirt(t_minirt *minirt);
void		ft_free_array(char ***argv);
void		free_float_pointer(void **str);
void		render_minirt(t_minirt *rt);
void		write_color(int x, int y, t_col color, t_minirt rt);
void		handle_sphere_move(int keycode, t_minirt *minirt);
void		handle_light_move(int keycode, t_minirt *minirt);
void		handle_camera_move(int keycode, t_minirt *minirt);
void		update_angle(float *angle_x, float *angle_z, t_vect v);
void		append_object(t_shape **lst, t_shape *new_shape);
void		hit_surface(t_ray *ray, t_shape *shape, t_hit **hit);
void		save_hit(float *max_dist, t_hit **near, t_hit *hit, int *in);
void		free_scene(t_scene *sc);
void		free_hit(t_hit *hit);
void		handle_plane_move(int keycode, t_minirt *minirt);
void		ft_swap(float *t1, float *t2);
void		normalize_vector(t_vect *vec);
void		print_matrix(t_mat mat);
void		activate_axis(int keycode, t_minirt *minirt);
void		moving_plane(int keycode, t_minirt *minirt);
void		resizing_sphere(int keycode, t_minirt *minirt);
void		moving_sphere(int keycode, t_minirt *minirt);
void		quit_move_mode(int keycode, t_minirt *minirt);
void		resizing_cylinder(int keycode, t_minirt *minirt);
void		moving_cylinder(int keycode, t_minirt *minirt);
void		rotating_plane(int keycode, t_minirt *minirt);
void		rotating_cylinder(int keycode, t_minirt *minirt);
void		rotating_camera(int keycode, t_minirt *minirt);
void		quit_elem_move_mode(int keycode, t_minirt *minirt);
void		activate_elem_rotation(int keycode, t_minirt *minirt);
void		activate_elem_axis(int keycode, t_minirt *minirt);
void		moving_light(int keycode, t_minirt *minirt);
void		moving_camera(int keycode, t_minirt *minirt);
void		key_use(void);
void		instruction_one(void);
void		instruction_two(void);
void		free_scenes(t_scene *sc);

char		**split_line(char *input);
char		*parse_comment(char *line);

int			main_check(t_minirt *minirt, int argc, char *filename);
int			main(int argc, char **argv);
int			puterror(char *msg);
int			file_exist(const char *filename);
int			file_exist(const char *filename);
int			check_comment(char **scene);
int			ft_arr_len(char **arr);
int			is_valid_extension(const char *filename);
int			is_duplicate(int total, char *msg);
int			is_mand_id(char *args, char id);
int			is_id(char *args, char *id);
int			validate_scene(t_minirt *minirt);
int			valid_compo(char id, char expct, int *nbr_tot, const char *name);
int			process_object(t_minirt *rt, char *id);
int			is_valid_scene(t_minirt *minirt);
int			is_valid_element(t_minirt *minirt, char **scene, t_type *id);
int			validate_line_format(t_minirt *minirt);
int			process_line(t_minirt *minirt);
int			valid_line_loop(t_minirt *minirt, int fd);
int			valid_line(t_minirt *minirt, const char *filename);
int			is_valid_ambient(char **line, t_minirt *minirt);
int			is_valid_camera(t_minirt *minirt, char **line);
int			is_valid_light(t_minirt *minirt, char **line);
int			init_mlx(t_minirt *rt);
int			setup_key(int keycode, t_minirt *minirt);
int			mouse_hook(int button, int x, int y, t_minirt *minirt);
int			close_window(t_minirt *minirt);
int			free_ret(char *str);
int			init_vector(t_vect *target, t_vect *source);
int			init_color(t_col *target, t_col *source);
int			valid_set(char *set, int is_float, float min_value, char *msg);
int			valid_cylinder_comp(char **line);
int			extra_data_cylinder(char **line);
int			extra_data_sphere(char **line);
int			extra_data_plane(char **line);
int			compare_mat(t_mat a, t_mat b);
int			lst_len(t_shape *lst);
int			hit_object(t_ray *ray, t_minirt *rt, float max);
int			is_valid_object(t_minirt *minirt, char **line, t_type id, int pos);
int			check_scene(t_minirt *minirt, t_type *id, int *i);
int			solve_quad(float *t, t_vect ray_dir, t_vect ray_orig,
				t_shape *shape);
int			solve_plane(float *var, t_vect ray_dir, t_vect ray_orig,
				t_shape *shape);
int			solve_cylinder(float *t, t_vect ray_dir, t_vect ray_orig,
				t_shape *shape);
int			manage_error(t_minirt *minirt, t_shape *obj, int *on_success);

bool		is_empty(const char *str);
bool		check_float(const char *str, int *is_dec, int *is_digit);
bool		is_valid_float(const char *str);
bool		is_valid_color(const char *str);
bool		is_valid_pos(const char *str);
bool		clear_buffer(int fd);
bool		is_norm_vector(char *str);
bool		is_norm(char *str);
bool		init_image(t_minirt *rt, t_set *set);
bool		invertible(t_mat a);

float		solve_second_degree(float a, float b, float c);
float		dot_product(t_vect a, t_vect b);
float		magnitude(t_vect a);
float		clamp_color(float color, float min, float max);
float		calcul_cos(t_vect a, t_vect b);
float		calcul_sin(t_vect a, t_vect b);
float		rounded(float value, float min);
float		determinant(t_mat a);
float		cofactor(t_mat a, int i, int j);
float		minor(t_mat a, int i, int j);
float		solve_quadratic(float b, float c);
float		length(t_vect *u, t_vect *v);
float		square(float a);

t_type		is_type(t_minirt *minirt);

t_ray		init_ray(t_minirt *rt);
t_ray		gen_primary_ray(t_camera cam, int i, int j);
t_ray		new_ray(t_pt origin, t_vect direction);
t_ray		ray_transform(t_ray ray, t_mat a);

t_pt		position(t_ray ray, float distance);
t_pt		rotate_x(t_pt p, float angle);
t_pt		rotate_y(t_pt p, float angle);
t_pt		rotate_z(t_pt p, float angle);

t_tuple		mult_mat_tp(t_mat a, t_tuple b);
t_tuple		new_tuple(float x, float y, float z);
t_tuple		new_point(float x, float y, float z);
t_tuple		new_vect(float x, float y, float z);
t_tuple		mult_mat_tp(t_mat a, t_tuple b);
t_tuple		rotate_on_point(t_tuple p, t_mat rot_mat);

t_vect		new_vect(float x, float y, float z);
t_vect		add_vect(t_vect a, t_vect b);
t_vect		sub_vect(t_vect a, t_vect b);
t_vect		scale(t_vect a, float nbr);
t_vect		div_vect(t_vect a, float nbr);
t_vect		to_neg_vect(t_vect a);
t_vect		cross_product(t_vect a, t_vect b);
t_vect		normalize(t_vect a);
t_vect		compute_ray_dir(t_camera cam, int i, int j);
t_vect		mult_mat_vect(t_mat a, t_vect b);
t_vect		rotate_vectoriel(t_vect v, t_vect orient);
t_vect		rotate_vect(t_vect v, float angle_x, float angle_y, float angle_z);
t_vect		rotate_around_center(t_vect point, t_vect center, float angle[3]);

t_col		new_color(float r, float g, float b);
t_col		add_color(t_col a, t_col b);
t_col		sub_color(t_col a, t_col b);
t_col		scale_color(float k, t_col a);
t_col		color_product(t_col a, t_col b);
t_col		take_min(t_col color, float max);
t_col		put_color(t_hit *hit);
t_col		ambient_light(t_ambient ambient, t_col color);
t_col		diffuse_light(t_light *light, t_hit *hit, t_col color);
t_col		put_light(t_minirt *rt, t_scene *sc, t_hit *hit, t_col color);
t_col		shadow(t_col color, float intensity);
t_col		convert_color(t_col color, float div);

t_mat		rotation_mat_axis(float angle, t_vect axis);
t_mat		camera_view(t_vect forward, t_vect world_up);
t_mat		create_mat(float mat[MAX][MAX], int size);
t_mat		identity_mat(void);
t_mat		submatrix(t_mat a, int rem_i, int rem_j);
t_mat		inverse(t_mat a);
t_mat		transpose(t_mat a);
t_mat		rotate_on_z(float degree);
t_mat		rotate_on_y(float degree);
t_mat		rotate_on_x(float degree);
t_mat		multiply_mat(t_mat a, t_mat b);
t_mat		mat_rot(t_vect v);
t_mat		translation(float x, float y, float z);
t_mat		scaling(float x, float y, float z);
t_mat		rotate_xyz(float a_x, float a_y, float a_z);
t_mat		rotate_on_x(float degree);
t_mat		rotate_on_y(float degree);
t_mat		rotate_on_z(float degree);
t_mat		inverse(t_mat a);
t_mat		rotation_mat_axis(float angle, t_vect axis);

t_hit		*sphere_intersect(t_ray *ray, t_sphere *sp);
t_hit		*return_hit(t_minirt *rt, t_ray *ray);
t_hit		*safe_calloc(void);
t_hit		*plane_intersect(t_ray *ray, t_plane *plane);
t_hit		*cylinder_intersect(t_ray *ray, t_cylinder *cylinder);
t_hit		*shape_intersect(t_ray *ray, t_shape *shape);

t_sphere	create_sphere(t_minirt *minirt, char **line);
int			create_plane(t_plane *new_plane, t_minirt *minirt, char **line);
t_cylinder	create_cylinder(t_minirt *minirt, char **line);

size_t		check_coma(char const *s, char c);

#endif
