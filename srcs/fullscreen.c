/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:04:13 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/11/20 18:14:48 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>

void	wrap_up(t_xvar **xvar, t_win_list **new_win, XGCValues *xgcv)
{
	XSetWMProtocols(xvar[0]->display, new_win[0]->window,
		&(xvar[0]->wm_delete_window), 1);
	xgcv[0].foreground = -1;
	xgcv[0].function = GXcopy;
	xgcv[0].plane_mask = AllPlanes;
	new_win[0]->gc = XCreateGC(xvar[0]->display, new_win[0]->window,
			GCFunction | GCPlaneMask | GCForeground, &xgcv[0]);
	new_win[0]->next = xvar[0]->win_list;
	xvar[0]->win_list = new_win[0];
	bzero(&(new_win[0]->hooks), sizeof(new_win[0]->hooks));
	XMapRaised(xvar[0]->display, new_win[0]->window);
	mlx_int_wait_first_expose(xvar[0], new_win[0]->window);
}

void	*my_mlx_new_window(t_xvar *xvar, int size_x, int size_y, char *title)
{
	t_win_list				*new_win;
	XSetWindowAttributes	xswa;
	XGCValues				xgcv;
	Atom					wm_state;
	Atom					fullscreen;

	xswa.background_pixel = 0;
	xswa.border_pixel = -1;
	xswa.colormap = xvar->cmap;
	xswa.event_mask = 0xFFFFFF;
	new_win = malloc(sizeof(*new_win));
	if (!new_win)
		return ((void *)0);
	new_win->window = XCreateWindow(xvar->display, xvar->root, 0, 0,
			size_x - 1, size_y - 1, 0, CopyFromParent, InputOutput,
			xvar->visual, CWEventMask | CWBackPixel | CWBorderPixel
			| CWColormap, &xswa);
	wm_state = XInternAtom(xvar->display, "_NET_WM_STATE", False);
	fullscreen = XInternAtom(xvar->display, "_NET_WM_STATE_FULLSCREEN", False);
	XChangeProperty(xvar->display, new_win->window, wm_state, XA_ATOM, 32,
		PropModeReplace, (unsigned char *)&fullscreen, 1);
	mlx_int_anti_resize_win(xvar, new_win->window, size_x, size_y);
	XStoreName(xvar->display, new_win->window, title);
	wrap_up(&xvar, &new_win, &xgcv);
	return (new_win);
}
