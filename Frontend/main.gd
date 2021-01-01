extends Node2D

var node = load("res://node.tscn")
var text = load("res://textLabel.tscn")

var current_node = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


func _on_Button_pressed():
	var newNode = node.instance()
	match current_node:
		0:
			newNode.title = "Sprite File"
		1:
			newNode.title = "Animated Sprite File"
	newNode.offset += (get_viewport().get_mouse_position() + $GraphEdit.scroll_offset) * $GraphEdit.zoom
	$GraphEdit.add_child(newNode)
	pass # Replace with function body.

func create_entry(txt,file_or_directory):
	var newText = text.instance()
	newText.get_child(0).text = txt
	if(file_or_directory == 0):
		newText.get_child(0).set_f()
	$ScrollContainer/VBoxContainer2.add_child(newText)
	pass
	
func _on_GraphEdit_popup_request(position):
	var p = $GraphEdit/PopupMenu
	p.show()
	p.set_position(position)
	pass # Replace with function body.


func _on_GraphEdit_gui_input(event):
	if event is InputEventMouseMotion:
		$GraphEdit/PopupMenu.hide()
	pass # Replace with function body.

func clear_files():
	for child in $ScrollContainer/VBoxContainer2.get_children():
		child.queue_free()

func _on_PopupMenu_id_pressed(ID):
	current_node = ID
	pass # Replace with function body.

func calc_dir(txt, caller): # If caller is asserted, update text in TextEdit
	if caller == 1:
		txt = $TextEdit.text + txt
		$TextEdit.text = txt
	clear_files()
	var directory = Directory.new()
	var error = directory.open(txt)
	if error == OK:
		directory.list_dir_begin()
		var file_name = directory.get_next()
		while (file_name != ""):
			if directory.current_is_dir():
				create_entry(file_name + "/",1)
			else:
				var length = file_name.length()
				var sprite_slice = "none"
				var asprite_slice = "none"
				if length > 7:
					sprite_slice = file_name.right(length - 7)
				if length > 8:
					asprite_slice = file_name.right(length - 8)
				if sprite_slice == ".sprite":
					create_entry(file_name,0)
				elif asprite_slice == ".asprite":
					create_entry(file_name,0)
			file_name = directory.get_next()
	pass
	
func _on_TextEdit_text_changed():
	calc_dir($TextEdit.text,0)
	pass # Replace with function body.
