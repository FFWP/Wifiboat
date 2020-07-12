package com.example.yaokongqi;
import  android.os.AsyncTask;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import  java.net.Socket;

public class MassageSend extends AsyncTask<String> {
    Socket s;
    DataOutputStream dos;
    PrintWriter pw;

    protected void doInBackground(Void){
     String massage = void[0];
            try {
                s=new Socket("192.168.0.99",7800);
                pw=new PrintWriter(s.getOutputStream());
                pw.flush();
                pw.close();
                s.close();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return null;
   }

}
