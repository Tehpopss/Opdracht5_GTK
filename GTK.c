#include <gtk/gtk.h>
#include <wiringPi.h>

void button_clicked(GtkWidget *widget,gpointer data)
{   
    if(digitalRead(21) == LOW){
        digitalWrite(21, HIGH);
        g_print("GPIO21 = HIGH \n");
    }
    else{
        digitalWrite(21,LOW);
        g_print("GPIO21 = LOW \n");
    }
}

void main (int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(21,OUTPUT); //GPIO 21
    pinMode(22,OUTPUT); //GPIO 22
    gtk_init (&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label ("Change State GPIO21");
    g_signal_connect(btn,"clicked",G_CALLBACK(button_clicked),NULL);
    gtk_container_add (GTK_CONTAINER (win), btn);
    gtk_widget_show_all (win);
    gtk_main ();
}