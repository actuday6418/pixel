extends Button

var file_or_directory = 1

func set_f():
	file_or_directory = 0
	pass

func _ready():
	pass 


func _on_Button_pressed():
	if file_or_directory == 1:
		get_tree().root.get_child(0).calc_dir(text,1)
	else:
		pass
	pass # Replace with function body.
