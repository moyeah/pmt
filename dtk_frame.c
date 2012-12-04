#include <gtk/gtk.h>

GtkWidget *
dtk_frame (const char *title)
{
  GtkWidget *label;
  GtkWidget *frame;

  label = gtk_label_new (NULL);
  gtk_label_set_markup (GTK_LABEL (label),
                        g_markup_printf_escaped ("<b>%s</b>", title));

  frame = gtk_frame_new (NULL);
  gtk_frame_set_label_widget (GTK_FRAME (frame), label);

  return frame;
}
