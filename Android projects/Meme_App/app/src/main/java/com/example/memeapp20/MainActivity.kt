package com.example.memeapp20

import android.content.Intent
import android.graphics.drawable.Drawable
import android.media.Image
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.Toast
import com.android.volley.Request
import com.android.volley.Response
import com.android.volley.toolbox.JsonObjectRequest
import com.android.volley.toolbox.StringRequest
import com.android.volley.toolbox.Volley
import com.bumptech.glide.Glide
import com.bumptech.glide.load.DataSource
import com.bumptech.glide.load.engine.GlideException
import com.bumptech.glide.request.RequestListener
import com.bumptech.glide.request.target.Target
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    lateinit var img_meme : ImageView
    lateinit var btn_share : Button
    lateinit var btn_next : Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        img_meme = findViewById(R.id.Img_meme)
        btn_share = findViewById(R.id.Btn_share)
        btn_next = findViewById(R.id.Btn_next)


        Btn_next.setOnClickListener {
            nextmeme()
           }

        Btn_share.setOnClickListener {
         sharememe()
        }

        loadmeme()

    }

    private fun loadmeme():Unit{

        val queue = Volley.newRequestQueue(this)
        val url = "https://meme-api.herokuapp.com/gimme"
        profressbar.visibility = View.VISIBLE

// Request a string response from the provided URL.
        val jsonObjectRequest = JsonObjectRequest(
            Request.Method.GET, url,null,
            { response ->

                val url = response.getString("url")
                Glide.with(this).load(url).listener(object : RequestListener<Drawable>{

                    override fun onLoadFailed(
                        e: GlideException?,
                        model: Any?,
                        target: Target<Drawable>?,
                        isFirstResource: Boolean
                    ): Boolean {
                        profressbar.visibility = View.GONE
                        return false
                    }

                    override fun onResourceReady(
                        resource: Drawable?,
                        model: Any?,
                        target: Target<Drawable>?,
                        dataSource: DataSource?,
                        isFirstResource: Boolean
                    ): Boolean {
                        profressbar.visibility = View.GONE
                        return false
                    }
                }).into(img_meme)

            },
            {
                Toast.makeText(this@MainActivity,"something wrong",Toast.LENGTH_LONG).show()
            })

// Add the request to the RequestQueue.
        queue.add(jsonObjectRequest)


    }


    fun sharememe():Unit{

     val intent = Intent(Intent.ACTION_SEND)
        intent.type = "text/plain"
        intent.putExtra(Intent.EXTRA_TEXT,"share this meme")

        val chooser = Intent.createChooser(intent,"share meme")
        startActivity(chooser)

    }


    fun nextmeme():Unit{

      loadmeme()
    }

 }