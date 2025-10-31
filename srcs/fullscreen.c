/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullscreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:04:13 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/22 12:54:33 by rmota-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "../minilibx-linux/mlx_int.h"
#include <X11/Xlib.h>
#include <X11/Xatom.h>

void	*my_mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
{
	t_win_list				*new_win;
	XSetWindowAttributes	xswa;
	XGCValues				xgcv;

	xswa.background_pixel = 0;
	xswa.border_pixel = -1;
	xswa.colormap = xvar->cmap;
	/*
	xswa.event_mask = ButtonPressMask | ButtonReleaseMask | ExposureMask |
		KeyPressMask | KeyReleaseMask | StructureNotifyMask;
	*/
	/* xswa.event_mask = ExposureMask; */
	xswa.event_mask = 0xFFFFFF;	/* all events */
	if (!(new_win = malloc(sizeof(*new_win))))
		return ((void *)0);
	new_win->window = XCreateWindow(xvar->display,xvar->root,0,0,size_x,size_y,
					0,CopyFromParent,InputOutput,xvar->visual,
					CWEventMask|CWBackPixel|CWBorderPixel|
					CWColormap,&xswa);      
	Atom wm_state = XInternAtom(xvar->display, "_NET_WM_STATE", False);
	Atom fullscreen = XInternAtom(xvar->display, "_NET_WM_STATE_FULLSCREEN", False);
	XChangeProperty(xvar->display, new_win->window, wm_state, XA_ATOM, 32,
                PropModeReplace, (unsigned char *)&fullscreen, 1);
	mlx_int_anti_resize_win(xvar,new_win->window,size_x,size_y);
	XStoreName(xvar->display,new_win->window,title);
	XSetWMProtocols(xvar->display, new_win->window, &(xvar->wm_delete_window), 1);
	xgcv.foreground = -1;
	xgcv.function = GXcopy;
	xgcv.plane_mask = AllPlanes;
	new_win->gc = XCreateGC(xvar->display,new_win->window,
				GCFunction|GCPlaneMask|GCForeground,&xgcv);
	new_win->next = xvar->win_list;
	xvar->win_list = new_win;
	/*
	new_win->mouse_hook = mlx_int_do_nothing;
	new_win->key_hook = mlx_int_do_nothing;
	new_win->expose_hook = mlx_int_do_nothing;
	*/
	bzero(&(new_win->hooks), sizeof(new_win->hooks));
	XMapRaised(xvar->display,new_win->window);
	mlx_int_wait_first_expose(xvar,new_win->window);
	return (new_win);
}
