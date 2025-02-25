# miniRT

This project is an introduction to the beautiful world of Raytracing.
Once completed you will be able to render simple Computer-Generated-Images and you
will never be afraid of implementing mathematical formulas again.


# Research
background-color:: blue
	- ## Ray Tracing
	  background-color:: green
		- ### Dot Product
			- result is a number
		- ### Cross Product
			- result is a vector
- # Template
  background-color:: blue
	- #MiniRT
	  template:: rt
	  template-including-parent:: true
		- ## What I achieved
			-
		- ## What I'm working on
			-
		- ## What I need to do next time
			-
		- ## Todo List
			- ((67b74e46-1abf-4cc5-a921-c2dd6cd7b7a2))
	- ## Todo List
	  id:: 67b74e46-1abf-4cc5-a921-c2dd6cd7b7a2
		- # TODO Research
		  background-color:: blue
		  :LOGBOOK:
		  CLOCK: [2025-02-20 Thu 16:49:40]--[2025-02-20 Thu 20:29:58] =>  03:40:18
		  CLOCK: [2025-02-21 Fri 14:13:00]--[2025-02-21 Fri 14:44:11] =>  00:31:11
		  CLOCK: [2025-02-21 Fri 15:34:42]--[2025-02-21 Fri 15:35:23] =>  00:00:41
		  :END:
			- ## Basic Concepts
			  background-color:: green
				- ### Tuples
				  background-color:: pink
				  collapsed:: true
					- a **tuple** is an ordered collection of elements, typically used to represent points, vectors, colors, or other mathematical constructs. Unlike arrays, tuples usually have a fixed size and can contain different data types.
						- **For example, in ray tracing:**
							- A **point** in 3D space is often represented as a tuple: **(x, y, z, w)** (where `w = 1` for points).
							- A **vector** is similar but with `w = 0`, distinguishing it from a point.
							- A **color** might be stored as a tuple **(r, g, b, a)** for red, green, blue, and alpha (transparency).
					- Tuples are useful because they provide a structured way to store and manipulate data while maintaining clarity in mathematical operations like vector addition or dot products.
				- ### Overview of Operations
				  background-color:: pink
					- ![image.png](../assets/image_1740490462471_0.png)
					- ![image.png](../assets/image_1740490536620_0.png)
					-
		- # Ray Tracer Challenge
		  background-color:: blue
			- ## Tuples
			  background-color:: green
				- ### Differentiate tuples
				  background-color:: pink
					- DONE `is_point()`
					  :LOGBOOK:
					  CLOCK: [2025-02-21 Fri 14:54:24]--[2025-02-21 Fri 14:54:25] =>  00:00:01
					  CLOCK: [2025-02-21 Fri 15:14:36]--[2025-02-21 Fri 15:16:27] =>  00:01:51
					  :END:
					- DONE `is_vector()`
				- ### Create Point or Vector from Coordinates x,y,z
				  background-color:: pink
					- DONE `make_tuple`
					  :LOGBOOK:
					  CLOCK: [2025-02-21 Fri 14:55:42]--[2025-02-21 Fri 14:55:52] =>  00:00:10
					  CLOCK: [2025-02-21 Fri 15:34:33]--[2025-02-21 Fri 15:34:35] =>  00:00:02
					  :END:
				- ### Operations on Tuples
				  background-color:: pink
					- DONE code `ft_equal()`
					  :LOGBOOK:
					  CLOCK: [2025-02-21 Fri 15:51:03]--[2025-02-21 Fri 15:55:35] =>  00:04:32
					  :END:
						- ![image.png](../assets/image_1740149448186_0.png)
					-
