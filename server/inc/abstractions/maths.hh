//
// maths.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:05:32 2014 
// Last Update Fri Nov 14 15:06:32 2014 
//

#ifndef MATHS_HH_
# define MATHS_HH_

# include <cmath>

# include <SFML/System/Vector2.hpp>

# define ABS(a)		((unsigned int)((int)(a) > 0 ? (int)(a) : -(int)(a)))
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define MIN(a, b)	((a) < (b) ? (a) : (b))

# define RAD(a)		(((float)a) * M_PI / 180.0f)
# define DEG(a)		(((float)a) / M_PI * 180.0f)

# define NORM(v)	(sqrt((float)((v).x * (v).x + (v).y * (v).y)))
# define DISTANCE(u, v)	(ABS((u).x - (v).x) + ABS((u).y - (v).y))

#endif // !MATHS_HH_
