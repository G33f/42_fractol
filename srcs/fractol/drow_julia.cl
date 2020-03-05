#if defined(cl_khr_fp64)  // Khronos extension available?
#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#define DOUBLE_SUPPORT_AVAILABLE
#elif defined(cl_amd_fp64)  // AMD extension available?
#pragma OPENCL EXTENSION cl_amd_fp64 : enable
#define DOUBLE_SUPPORT_AVAILABLE
#endif

__kernel void draw(__global int* pixel, int win_size_x, int win_size_y, int max_iteration, double zoom, double shift_x,
				   double shift_y, double color, double c_x, double c_y)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	tmp;
	int		gid;
	int		iteration;
                                                                                                       
	x0 = 0;                                                                                            
	y0 = 0;                                                                                            
	gid = get_global_id(0);                                                                            
	y = (double)(gid / win_size_x) / zoom - shift_y;                                                   
	x = (double)(gid % win_size_x) / zoom - 3.0 / 2 - shift_x;                                         
	iteration = 0;                                                                                     
	while ((x * x + y * y) < 200 && iteration < max_iteration)
	{                                                                                                  
		tmp = x * x - y * y;                                                                           
		y = 2 * x * y + c_y;                                                                           
		x = tmp + c_x;                                                                                 
		iteration -= -1;                                                                               
	}
	tmp = (double)iteration - log2(log2((x * x) + (y * y))) + 9.0;
	double hx = 0.5 + 0.5 * cos(0.5 * tmp + (3.0 * color));
	double hy = 0.5 + 0.5 * cos(0.5 * tmp + (15.6 * color / 2));
	double hz = 0.5 + 0.5 * cos(0.5 * tmp + (5.6 * (-color)));
	if (iteration == max_iteration)
		pixel[gid] = 0;
	else
	{
		pixel[gid] = ((unsigned int) ((double) hx * 255) << (unsigned) 16);
		pixel[gid] = ((unsigned int) ((double) hy * 255) << (unsigned) 8) | pixel[gid];
		pixel[gid] = (unsigned char) ((double) hz * 255) | pixel[gid];
	}
}
