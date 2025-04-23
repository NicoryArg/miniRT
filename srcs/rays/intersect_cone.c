#include "../../includes/minirt.h"
#include "engine.h"

typedef struct s_cone_vals
{
	double t0;
	double t1;
}	t_cone_vals;

static void	swap_vals(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	validate_cone_hits(t_hitlist **xs, t_cone *cone, t_ray *ray, t_cone_vals d)
{
	double	y0;
	double	y1;

	y0 = ray->origin.y + d.t0 * ray->direction.y;
	y1 = ray->origin.y + d.t1 * ray->direction.y;
	if (d.t0 > d.t1)
		swap_vals(&d.t0, &d.t1);
	if (cone->min < y0 && y0 < cone->max)
		add_hit(xs, make_hit(d.t0, cone, CONE));
	if (cone->min < y1 && y1 < cone->max)
		add_hit(xs, make_hit(d.t1, cone, CONE));
}

void	intersect_cone(t_object *shape, t_ray *ray, t_hitlist **xs)
{
	t_cone			*cone;
	t_ray			*local_ray;
	t_cone_vals		d;
	double			a;
	double			b;
	double			c;
	double			disc;

	cone = (t_cone *)shape;
	local_ray = transform(ray, cone->base.transf);
	a = pow(local_ray->direction.x, 2) - pow(local_ray->direction.y, 2) + pow(local_ray->direction.z, 2);
	b = 2 * (local_ray->origin.x * local_ray->direction.x
		- local_ray->origin.y * local_ray->direction.y
		+ local_ray->origin.z * local_ray->direction.z);
	c = pow(local_ray->origin.x, 2) - pow(local_ray->origin.y, 2) + pow(local_ray->origin.z, 2);

	if (fabs(a) < EPSILON && fabs(b) < EPSILON)
	{
		free(local_ray);
		return ;
	}
	if (fabs(a) < EPSILON)
	{
		d.t0 = -c / (2 * b);
		add_hit(xs, make_hit(d.t0, cone, CONE));
		free(local_ray);
		return ;
	}
	disc = b * b - 4 * a * c;
	if (disc < 0)
	{
		free(local_ray);
		return ;
	}
	d.t0 = (-b - sqrt(disc)) / (2 * a);
	d.t1 = (-b + sqrt(disc)) / (2 * a);
	validate_cone_hits(xs, cone, local_ray, d);
	// TODO: intersect_cone_caps(xs, cone, *local_ray); if cone->closed
	free(local_ray);
}
