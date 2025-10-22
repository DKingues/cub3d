#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../includes/cub3d.h"

static void make_fullscreen(Display *d, Window w)
{
    Atom wm_state = XInternAtom(d, "_NET_WM_STATE", False);
    Atom fullscreen = XInternAtom(d, "_NET_WM_STATE_FULLSCREEN", False);

    XEvent xev;
    memset(&xev, 0, sizeof(xev));
    xev.type = ClientMessage;
    xev.xclient.window = w;
    xev.xclient.message_type = wm_state;
    xev.xclient.format = 32;
    xev.xclient.data.l[0] = 1;  // 1 = add
    xev.xclient.data.l[1] = fullscreen;
    xev.xclient.data.l[2] = 0;
    xev.xclient.data.l[3] = 0;
    xev.xclient.data.l[4] = 0;

    XSendEvent(d, w, False, SubstructureRedirectMask | SubstructureNotifyMask, &xev);
    XFlush(d);
}

int main(void)
{
    void *mlx = mlx_init();
    mlx_new_window(mlx, 800, 600, "Fullscreen test");

    // Get the underlying X11 handles safely from MLX
    Display *dpy = XOpenDisplay(NULL);
    if (!dpy)
    {
        fprintf(stderr, "Failed to open X display\n");
        return 1;
    }

    // Try to find the MLX window by its title
    Window root = DefaultRootWindow(dpy);
    Window target = 0;
    Atom prop = XInternAtom(dpy, "_NET_CLIENT_LIST", False);
    Atom type;
    int format;
    unsigned long nitems, bytes_after;
    unsigned char *data = NULL;

    if (XGetWindowProperty(dpy, root, prop, 0, (~0L), False, AnyPropertyType,
                           &type, &format, &nitems, &bytes_after, &data) == Success)
    {
        for (unsigned long i = 0; i < nitems; i++)
        {
            Window w = ((Window *)data)[i];
            char *name = NULL;
            if (XFetchName(dpy, w, &name) && name)
            {
                if (strcmp(name, "Fullscreen test") == 0)
                {
                    target = w;
                    XFree(name);
                    break;
                }
                XFree(name);
            }
        }
        if (data)
            XFree(data);
    }

    if (target)
    {
        usleep(300000); // wait 0.3s to let WM map the window
        make_fullscreen(dpy, target);
    }
    else
        fprintf(stderr, "Could not find window.\n");

    mlx_loop(mlx);
    XCloseDisplay(dpy);
    return 0;
}