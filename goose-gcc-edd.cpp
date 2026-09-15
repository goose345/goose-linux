#include <gtk/gtk.h>
#include <glib.h>
#include <stdio.h>

//==================================================
// Theme Colours
//==================================================

const char *BUTTON_BG         = "#000000";
const char *BUTTON_TEXT       = "#ffffff";
const char *BUTTON_BORDER     = "#ffffff";
const char *BUTTON_HOVER      = "#000000";

const char *BUTTON_CLICK      = "#ffffff";
const char *BUTTON_CLICK_TEXT = "#000000";

const char *WINDOW_BG         = "#000000";
const char *LABLE_TEXT        = "#ffffff";

//==================================================

static void on_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkApplication *app = GTK_APPLICATION(user_data);
    const char *label = gtk_button_get_label(button);


    if (g_strcmp0(label, "Laptop Mode") == 0)
    {
        g_spawn_command_line_async("sh -c \"xrandr --output HDMI-1-0 --off --output eDP --auto && feh --bg-fill /home/goose/Downloads/dark-starry-sky-stars-4k-9m-2560x1600.jpg\"", NULL);
    }
    else if (g_strcmp0(label, "Brie Mode") == 0)
    {
        g_spawn_command_line_async("sh -c \"xrandr --output HDMI-1-0 --mode 1920x1080 --rate 240 --output eDP --off && feh --bg-fill /home/goose/Downloads/1080.png\"", NULL);
    }
    else if (g_strcmp0(label, "Jinx Mode") == 0)
    {
    g_spawn_command_line_async("sh -c \"xrandr --output HDMI-1-1 --auto --output eDP --off && feh --bg-fill /home/goose/Downloads/1080.jpg\"", NULL);
    }
   else if (g_strcmp0(label, "Orange Mode") == 0)
    {
        g_spawn_command_line_async("echo i am linux man", NULL);
    }
    else if (g_strcmp0(label, "Shutdown Mode") == 0)
    {
        g_spawn_command_line_async("loginctl poweroff" , NULL);
    }
    else if (g_strcmp0(label, "Reboot Mode") == 0)
    {
        g_spawn_command_line_async("loginctl reboot", NULL);
    }
    else if (g_strcmp0(label, "Quit") == 0)
    {
        g_application_quit(G_APPLICATION(app));
    }
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkCssProvider *css;

   window = gtk_application_window_new(app);

GtkSettings *settings = gtk_settings_get_default();

gtk_window_set_title(
    GTK_WINDOW(window),
    "goose-gcc-edition-V1"
);

gtk_window_set_default_size(
    GTK_WINDOW(window),
    470,
    500
);
    grid = gtk_grid_new();

    gtk_grid_set_row_spacing(GTK_GRID(grid), 15);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);

    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid, GTK_ALIGN_CENTER);

    //==================================================
    // Labels
    //==================================================

    GtkWidget *title  = gtk_label_new("goose-gcc-edition-V1");
    GtkWidget *label1 = gtk_label_new("Monitor's");
    GtkWidget *label2 = gtk_label_new("Power");

    //==================================================
    // Buttons
    //==================================================

    GtkWidget *top1 = gtk_button_new_with_label("Laptop Mode");
    GtkWidget *top2 = gtk_button_new_with_label("Brie Mode");
    GtkWidget *top3 = gtk_button_new_with_label("Jinx Mode");

    GtkWidget *mid1 = gtk_button_new_with_label("Orange Mode");
    GtkWidget *mid2 = gtk_button_new_with_label("Shutdown Mode");
    GtkWidget *mid3 = gtk_button_new_with_label("Reboot Mode");

    GtkWidget *bottom = gtk_button_new_with_label("Quit");

    // Make Quit button smaller
    gtk_widget_set_name(bottom, "quit_button");

    GtkWidget *buttons[] =
    {
        top1, top2, top3,
        mid1, mid2, mid3,
        bottom
    };

for (int i = 0; i < 7; i++)
{
    // Stop buttons from receiving keyboard focus
    gtk_widget_set_focusable(buttons[i], FALSE);

    // Keep mouse clicking working
    g_signal_connect(
        buttons[i],
        "clicked",
        G_CALLBACK(on_button_clicked),
        app);
}
    //==================================================
    // Layout
    //==================================================

    gtk_grid_attach(GTK_GRID(grid), title, 0, 0, 3, 1);

    gtk_grid_attach(GTK_GRID(grid), label1, 0, 2, 3, 1);

    gtk_grid_attach(GTK_GRID(grid), top1, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), top2, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), top3, 2, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), label2, 0, 4, 3, 1);

    gtk_grid_attach(GTK_GRID(grid), mid1, 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), mid2, 1, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), mid3, 2, 5, 1, 1);

    // Spacer
    GtkWidget *space = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), space, 0, 6, 3, 1);

    // Quit button
    gtk_grid_attach(GTK_GRID(grid), bottom, 1, 7, 1, 1);

    gtk_window_set_child(GTK_WINDOW(window), grid);

    //==================================================
    // CSS
    //==================================================

    css = gtk_css_provider_new();

    char css_text[4096];

snprintf(css_text, sizeof(css_text),
    "window {"
    "  background-color: %s;"
    "}"

    "label {"
    "  color: %s;"
    "  font-weight: bold;"
    "}"

    "button {"
    "  background-image: none;"
    "  background-color: %s;"
    "  color: %s;"
    "  border: 2px solid %s;"
    "  border-radius: 0px;"
    "  padding: 4px 8px;"
    "  min-width: 120px;"
    "  min-height: 35px;"
    "  transition: none;"
    "}"

    "button label {"
    "  color: %s;"
    "}"

    "button:hover {"
    "  background-image: none;"
    "  background-color: %s;"
    "}"

    "button:active {"
    "  background-image: none;"
    "  background-color: %s;"
    "}"

    "button:active label {"
    "  color: %s;"
    "}",

    WINDOW_BG,          
    LABLE_TEXT,        

    BUTTON_BG,          
    BUTTON_TEXT,        
    BUTTON_BORDER,      

    BUTTON_TEXT,        

    BUTTON_HOVER,       

    BUTTON_CLICK,        
    BUTTON_CLICK_TEXT 

);
    gtk_css_provider_load_from_string(css, css_text);

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(css),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    g_object_unref(css);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "com.goose.gcc",
        G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(
        app,
        "activate",
        G_CALLBACK(activate),
        NULL);

    status = g_application_run(
        G_APPLICATION(app),
        argc,
        argv);

    g_object_unref(app);

    return status;
}
