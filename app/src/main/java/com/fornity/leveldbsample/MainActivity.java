package com.fornity.leveldbsample;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.fornity.leveldbsample.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("leveldbsample");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        TextView tv = binding.sampleText;
        tv.setText("Launch count: " + getLaunchCount(getFilesDir().getAbsolutePath()));
    }

    public native String getLaunchCount(final String filesPath);
}