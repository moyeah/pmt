#include <gtk/gtk.h>

static const gchar *menus[] = {
  "_File",
  "_Edit",
  "_Search",
  "_View",
  "_Help",
   NULL};

static const gchar *file[] = {
  GTK_STOCK_NEW,
  SEPARATOR,
  GTK_STOCK_QUIT,
  NULL
};

static const gchar *edit[] = {
  GTK_STOCK_CUT,
  NULL
};

GtkWidget *
dtk_menu_bar ()
{
  GtkWidget *menu_bar;
  GtkWidget *menu;
  GtkWidget *menu_item;

  menu_bar = gtk_menu_bar_new ();
  menu = gtk_menu_new ();

  int i;
  for (i = 0; menus[i] != NULL; i++)
  {
    menu_item = gtk_menu_item_new_with_mnemonic (menus[i]);

    gtk_menu_shell_append (GTK_MENU_SHELL (menu_bar), menu_item);
  }

  return menu_bar;
}
