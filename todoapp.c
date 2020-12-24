#include <gtk/gtk.h>

static void add_line(GtkWidget *widget, gpointer data)
{
	// check if the text is past the max for the line,
	// and go to a new line if it is.
	
	// create new textview
	GtkWidget *tv = gtk_text_view_new();
}

int main(int argc, char *argv[])
{
	// init vars
	GtkBuilder *builder;
	GObject *window;
	GObject *textView;
	GtkTextBuffer *textBuffer;
	GError *error = NULL;

	gtk_init (&argc, &argv);

	// Construct a GtkBuilder instance and load UI
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
	{
	  g_printerr ("Error loading file: %s\n", error->message);
	  g_clear_error (&error);
	  return 1;
	}

	// Set the app to quit when the window is closed
	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// connect editing signal to the textview
	textView = gtk_builder_get_object(builder, "line1");
	
	textBuffer = gtk_text_view_get_buffer( GTK_TEXT_VIEW(textView) );
	g_signal_connect(textBuffer, "insert-text", G_CALLBACK(add_line), NULL);


	gtk_main ();

	return 0;
}