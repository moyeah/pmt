#include <gtk/gtk.h>

#include "dtk.h"

int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *menu_bar;
  GtkWidget *frame;

  gtk_init (&argc, &argv);

  window = dtk_window ("Project Management Tool");

  grid = gtk_grid_new ();
  gtk_container_add (GTK_CONTAINER (window), grid);

  menu_bar = dtk_menu_bar ();
  gtk_grid_attach (GTK_GRID (grid), menu_bar, 0, 0, 1, 1);

  //frame = dtk_frame ("Projects");
  //gtk_box_pack_start (GTK_BOX (main_vbox), frame, FALSE, TRUE, 0);

  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
