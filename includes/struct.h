/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tambinin <tambinin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:44:49 by candriam          #+#    #+#             */
/*   Updated: 2025/03/16 15:17:26 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TITLE "miniRT v0.1"
# define WIN_WIDTH 700.0
# define WIN_HEIGHT 400.0
# define EPSILON 1e-4
# define MIN_SIZE 0.2
# define ESC 65307
# define MAX_ID 15
# define MAX 4
# define USE 5
# define COUNT 16
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122
# define K_SUM 65451
# define K_MIN 65453
# define SPACE 32

typedef struct s_tuple
{
	float				x;
	float				y;
	float				z;
}						t_tuple;

typedef struct s_tuple	t_vect;

typedef struct s_tuple	t_pt;

typedef struct s_col	t_col;

typedef struct s_mat	t_mat;

typedef struct s_mat
{
	float				mat[MAX][MAX];
	int					size;
}						t_mat;

typedef struct s_col
{
	float				red;
	float				green;
	float				blue;
}						t_col;

typedef enum e_type
{
	ERR,
	A,
	C,
	L,
	PL,
	SP,
	CY,
	CMT,
	DUP,
	TOTAL,
	NOT_ID
}						t_type;

typedef struct s_camera
{
	char				id;
	float				fov;
	int					is_active;
	t_vect				position;
	t_vect				initial_pos;
	t_vect				orientation;
	t_vect				initial_orient;
	t_vect				up;
	t_vect				right;
	t_vect				forward;
	t_vect				world_up;
}						t_camera;

typedef struct s_ambient
{
	char				id;
	float				ratio;
	t_col				color;
}						t_ambient;

typedef struct s_light
{
	char				id;
	float				intensity;
	int					is_active;
	t_vect				position;
	t_col				color;
}						t_light;

typedef struct s_cylinder
{
	char				*id;
	float				height;
	float				radius;
	t_vect				normal;
	t_vect				base;
	t_col				color;
}						t_cylinder;

typedef struct s_plane
{
	char				*id;
	t_vect				position;
	t_vect				normal;
	t_col				color;
}						t_plane;

typedef struct s_sphere
{
	char				*id;
	float				radius;
	t_vect				position;
	t_col				color;
}						t_sphere;

typedef union u_form
{
	t_plane				pl;
	t_sphere			sp;
	t_cylinder			cy;
}						t_form;

typedef enum e_fig
{
	PLANE,
	SPHERE,
	CYLINDER
}						t_fig;

typedef struct s_translation
{
	int					is_active;
	int					cam_is_active;
	int					zoom_is_active;
	int					light_is_active;
	int					axis_on[3];
	int					direction;
}						t_translation;

typedef struct s_rotation
{
	int					is_active;
	int					cam_is_active;
	int					axis_on[3];
	int					direction;
	float				angle_x;
	float				angle_y;
	float				angle_z;
	t_mat				matrix;
}						t_rotation;

typedef struct s_resize
{
	int					is_active_r;
	int					is_active_h;
	float				height;
	float				radius;
}						t_resize;

typedef struct s_shape
{
	int					pos;
	int					is_active;
	t_fig				fig;
	t_form				form;
	t_translation		translation;
	t_rotation			rotation;
	t_resize			resize;
	struct s_shape		*next;
}						t_shape;

typedef struct s_set
{
	void				*mlx;
	void				*win;
	void				*image;
	char				*img_data;
	int					width;
	int					height;
	int					bpp;
	int					line_len;
	int					endian;
}						t_set;

typedef struct s_scene
{
	int					is_active;
	t_translation		translation;
	t_rotation			rotation;
	t_ambient			ambient;
	t_camera			camera;
	t_light				light;
	t_shape				*shape;
}						t_scene;

typedef struct s_hit
{
	int					pos;
	float				distance;
	t_form				form;
	t_fig				fig;
	t_pt				point;
	t_vect				normal;
	t_col				color;
}						t_hit;

typedef struct s_ray
{
	t_hit				*hit;
	t_pt				origin;
	t_vect				direction;
}						t_ray;

typedef struct s_minirt
{
	int					nbr_ambient;
	int					dup_ambient;
	int					nbr_camera;
	int					dup_camera;
	int					nbr_light;
	int					dup_light;
	int					nbr_spheres;
	int					nbr_planes;
	int					nbr_cylinders;
	int					err;
	int					on_success;
	char				*line;
	char				*trimmed;
	char				**array;
	t_set				*set;
	t_scene				*scene;
	t_shape				*obj_selected;
}						t_minirt;

#endif
