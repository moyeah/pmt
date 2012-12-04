#include <gtk/gtk.h>

#include "dtk.h"

int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *main_vbox;
  GtkWidget *frame;

  gtk_init (&argc, &argv);

  window = dtk_window ("Project Management Tool");

  main_vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (window), main_vbox);

  frame = dtk_frame ("Projects");
  gtk_box_pack_start (GTK_BOX (main_vbox), frame, FALSE, TRUE, 0);

  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}
