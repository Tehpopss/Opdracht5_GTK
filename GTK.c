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

void button_clicked2(GtkWidget *widget,gpointer data)
{   
    if(digitalRead(22) == LOW){
        digitalWrite(22, HIGH);
        g_print("GPIO22 = HIGH \n");
    }
    else{
        digitalWrite(22,LOW);
        g_print("GPIO22 = LOW \n");
    }
}

void button_clicked3(GtkWidget *widget,gpointer data3)
{   
    if(digitalRead(23) == LOW){
        g_print("GPIO 23 = LOW \n");
    }else{
        g_print("GPIO 23 = HIGH \n");
    }
}

void button_clicked4(GtkWidget *widget,gpointer data4)
{   
    if(digitalRead(24) == LOW){
        g_print("GPIO 24 = LOW \n");
    }else{
        g_print("GPIO 24 = HIGH \n");
    }
}

void main (int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(21,OUTPUT); //GPIO 21
    pinMode(22,OUTPUT); //GPIO 22
    pinMode(23,INPUT); //GPIO 23
    pinMode(24,INPUT); //GPIO 24
    gtk_init (&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label ("Change State GPIO21");
    g_signal_connect(btn,"clicked",G_CALLBACK(button_clicked),NULL);
    GtkWidget *btn2 = gtk_button_new_with_label("Change State GPIO22");
    g_signal_connect(btn2,"clicked",G_CALLBACK(button_clicked2),NULL);
    GtkWidget *btn3 = gtk_button_new_with_label("Show State of GPIO23");
    g_signal_connect(btn3,"clicked",G_CALLBACK(button_clicked3),NULL);
    GtkWidget *btn4 = gtk_button_new_with_label("Show State of GPIO24");
    g_signal_connect(btn4,"clicked",G_CALLBACK(button_clicked4),NULL);
    GtkWidget *box = gtk_vbox_new (FALSE,10);
    gtk_box_pack_start(GTK_BOX(box),btn, TRUE, TRUE,0);
    gtk_box_pack_start(GTK_BOX(box),btn2, TRUE, TRUE,0);
    gtk_box_pack_start(GTK_BOX(box),btn3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box),btn4, TRUE, TRUE, 0);
    gtk_container_add (GTK_CONTAINER(win),box);
    gtk_widget_show_all (win);
    gtk_main ();
}