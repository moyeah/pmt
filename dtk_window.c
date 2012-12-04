#include <gtk/gtk.h>

static gboolean
on_delete_event (GtkWidget *window,
                 GdkEvent  *event,
                 gpointer   data)
{
  GtkWidget *dialog;
  gboolean   response;

  dialog = gtk_message_dialog_new (GTK_WINDOW (window),
                                   GTK_DIALOG_DESTROY_WITH_PARENT,
                                   GTK_MESSAGE_QUESTION,
                                   GTK_BUTTONS_YES_NO,
                                   "Are you sure you want to quit?");
  gtk_window_set_title (GTK_WINDOW (dialog),
                        "Leaving application...");

  gint result = gtk_dialog_run (GTK_DIALOG (dialog));
  switch (result)
  {
    case GTK_RESPONSE_YES:
      response = FALSE;
      break;
    default:
      response = TRUE;
      break;
  }

  gtk_widget_destroy (dialog);

  return response;
}

static void
on_destroy (GtkWidget *window,
            gpointer   data)
{
  gtk_main_quit ();
}

GtkWidget *
dtk_window (const gchar *title)
{
  GtkWidget *window;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), title);
  gtk_window_set_default_size (GTK_WINDOW (window),
                               gdk_screen_width () * 3/4,
                               gdk_screen_height () * 3/4);

  g_signal_connect (window, "delete-event",
                    G_CALLBACK (on_delete_event), NULL);
  g_signal_connect (window, "destroy",
                    G_CALLBACK (on_destroy), NULL);

  return window;
}
