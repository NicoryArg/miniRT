/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:28:21 by nryser            #+#    #+#             */
/*   Updated: 2025/05/06 20:28:31 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define MAX_FILE 10240
# define MAX_LINE_LEN 51
# define MAX_SPHERES 30
# define MAX_LIGHTS 4
# define MAX_PLANES 4
# define MAX_CYLINDERS 4
# define MAX_CONES 4

#define PATTERN_STRIPE 		1
#define PATTERN_GRADIENT	2
#define PATTERN_RING		3
#define PATTERN_CHECKERS	4
#define PATTERN_UV_STRIPE	5
#define PATTERN_UV_GRADIENT	6
#define PATTERN_UV_CHECKERS	7

#define SHAPE_SPHERE	1
#define SHAPE_PLANE		2
#define SHAPE_CYLINDER	3
#define SHAPE_CONE		4

#include "minirt.h"
#include "engine.h"

typedef			t_tuple t_point3d;
typedef			t_tuple t_vector3d;
typedef struct	s_tokens t_tokens;

typedef enum	identifier
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
	CO,
	UFO,
}	e_id;
typedef struct s_id_count
{
	int	a;
	int	c;
	int	l;
	int	sp;
	int	pl;
	int	cy;
	int	co;
	int	total;
}	t_id_count;

typedef struct	s_tokens
{
	char			**tokens;	//2d array of all args for a given identifier
	e_id	type;		//identifier type (A, C, L, sp, cy, etc.)
	int				count;		//number of arguments (sp expects 4, A expects 3, etc.)
	t_tokens		*next;		//pointer to next identifier and it's arguments
}	t_tokens;

typedef struct	s_sphere_input
{
	t_point3d	position;
	double		diameter;
	t_colour	color;
	int			patt_type;
}	t_sphere_input;

typedef struct	s_plane_input
{
	t_point3d	position;
	t_vector3d	normal;
	t_colour	color;
	int			patt_type;
}	t_plane_input;

typedef struct	s_cylinder_input
{
	t_point3d	position;
	t_vector3d	normal;
	double		diameter;
	double		height;
	t_colour	color;
	int			patt_type;
} t_cylinder_input;

typedef struct s_cone_input
{
	t_point3d	position;
	t_vector3d	normal;
	double		diameter;
	double		min;
	double		max;
	t_colour	color;
	int			patt_type;
}	t_cone_input;

typedef struct s_parsed_scene
{
	double				ambient_ratio;  // [0,1]
	t_colour			ambient_color;
	int					has_ambient;

	t_point3d			camera_pos;
	t_vector3d			camera_dir;
	double				fov;
	int					has_camera;

	t_point3d			light_positions[MAX_LIGHTS];
	t_colour			light_colours[MAX_LIGHTS];
	int					light_count;
	double				brightness[MAX_LIGHTS];

	t_plane_input		planes[MAX_PLANES];
	int					plane_count;

	t_sphere_input		spheres[MAX_SPHERES];
	int					sphere_count;

	t_cylinder_input	cylinders[MAX_CYLINDERS];
	int					cylinder_count;

	t_cone_input		cones[MAX_CONES];
	int					cone_count;
}	t_parsed_scene;

typedef struct	s_input
{
	int				shapes;		//number of shape identifiers (sp, cy, etc.)
	char			**lines;	//2d array for each line of the input file
	t_tokens		*list;		//first pointer to linked list of tokens (for each line)
	t_id_count		count;		//count of each identifier type
	t_parsed_scene	sc;			//parsed scene struct
	bool			bonus;		//bonus flag
}	t_input;

//build_list.c
t_tokens	*create_token_node(char **tokens, e_id type);
void		append_token_node(t_tokens **head, t_tokens *new_node);
void		print_node(t_tokens *node);

//build_scene.c
t_object		**alloc_objects_array(t_parsed_scene *scene, int *total);
t_world			*convert_scene_to_world(t_parsed_scene *scene);
t_parsed_scene	init_parsed_scene(void);
void			dispatch_token(t_tokens *current, t_parsed_scene *scene);
t_parsed_scene	build_scene_from_tokens(t_tokens *head);

//check_file.c
int				check_file(int ac, char **av);

//copy_input.c
char			**copy_input(char *file);

//create_patterns.c
t_pattern	*create_pattern_by_type(int type, t_colour base, int shape_type);

//free_parse.c
void			free_array(char **array);

//validate_and_load.c

//parse_input.c
t_tokens		*parse_input(char **lines);

//entrypoint_parser.c
int				validate_and_load(int ac, char **av, t_input *data);
void			draw_scene_parsed(t_engine *engine, t_parsed_scene *scene);

//expected_identifiers.c
int	expected_identifiers(t_input *data, t_tokens *list, bool bonus);

//free_utils.c
void			free_array(char **array);
void			free_split(char **array);
void			free_token_node(t_tokens *node);
t_tokens		*free_tokens_list(t_tokens *head);

// is_float.c
int				is_float(const char *s);
int				is_int(char *s);

//load_shape.c
void			load_sphere(char **sp, t_parsed_scene *scene);
void			load_plane(char **tokens, t_parsed_scene *scene);
void			load_cylinder(char **tokens, t_parsed_scene *scene);
void			load_cone(char **tokens, t_parsed_scene *scene);

//load_unique.c
void			load_ambient(char **tokens, t_parsed_scene *scene);
void			load_camera(char **tokens, t_parsed_scene *scene);
void			load_light(char **tokens, t_parsed_scene *scene);

//parse_color.c
t_colour		parse_color(char *str);
int				is_color(const char *str);

//parse_tuple_utils.c
t_tuple			ft_point(double x, double y, double z);
t_tuple			ft_vector(double x, double y, double z);
t_tuple			parse_tuple(char *str, int type);
t_point3d		parse_point(char *str);
t_matrix		*align_up_vector(t_vector3d normal);

//parse_utils_vec.c
int				is_vec3(const char *str);
bool			is_normalized_vector(t_tuple v);

//parse_utils.c
int				skip_spaces_and_sign(const char *str, int *sign);
double			ft_atof(const char *str);
int				count_split(char **arr);

//split_lines.c
int				split_lines(char *str, char **lines);

//tokenize_lines.c
e_id		get_identifier(char *s);
t_tokens	*parse_input(char **lines);

//valid_add_ambient.c
int			valid_ambient(char **tokens);

//valid_add_camera.c
void		orientation_err(double x, double y, double z);
int			valid_orientation(char *str);
int			valid_camera(char **tokens);

//valid_add_cone.c
int			valid_cone(char **tokens);
int			add_cones(t_object **objects, t_parsed_scene *scene, int start);

//valid_add_cylinder.c
int			valid_cylinder(char **tokens);
int			add_cylinders(t_object **objects, t_parsed_scene *scene, int start);

//valid_add_light.c
int			valid_light_ratio(char *num);
int			valid_light(char **tokens, bool bonus);
void		add_lights(t_world *w, t_parsed_scene *scene);

//valid_add_plane.c
int			valid_plane(char **tokens);
int			add_planes(t_object **objects, t_parsed_scene *scene, int start);

//valid_add_sphere.c
int			valid_sphere(char **tokens);
int			add_spheres(t_object **objects, t_parsed_scene *scene, int start);

//valid_input.c
void		print_count(t_id_count count);
int			valid_input(t_input *data, bool bonus);

//ERROR MESSAGE UTILS


# define X ""R_B"Error\n❌ "RES""
# define O "✔ "GR""
# define TIP "Please ensure you separate values with spaces only -> ' '\n"
# define INVALID_INPUT "Invalid input\n"LILA"Tip: "TIP""RES"\n"
# define INVALID_ID ""X""RES"`"AKA"%s"RES"`is invalid identifier\n"
# define BRIGHT ""AKA"Light ratio out of range:"RES"    "
# define TOO_MANY_VEC3 "Too many or few args: "AKA"%s"RES"\n"
# define FAILED_SPLIT "❌ failed to split: `"AKA"%s"RES"`\n"
# define LONG_LINE "line too long! (max 50)\n"
#endif
