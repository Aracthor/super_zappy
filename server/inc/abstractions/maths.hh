//
// maths.hh for super_zappy in /home/aracthor/programs/projects/hub/super_zappy/server
// 
// Made by 
// Login   <aracthor@epitech.net>
// 
// Started on  Tue Oct 14 13:05:32 2014 
// Last Update Fri Oct 24 16:30:13 2014 
//

#ifndef MATHS_HH_
# define MATHS_HH_

# include <cmath>

# define ABS(a)		((int)(a) > 0 ? (int)(a) : -(int)(a))
# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define MIN(a, b)	((a) < (b) ? (a) : (b))

# define RAD(a)		((a) * M_PI / 180.0f)
# define DEG(a)		((a) / M_PI * 180.0f)

#endif // !MATHS_HH_
