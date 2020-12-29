extends Node2D

var node = load("res://node.tscn")

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
			newNode.title = "Rule"
	newNode.offset += get_viewport().get_mouse_position() + $GraphEdit.scroll_offset / $GraphEdit.zoom
	$GraphEdit.add_child(newNode)
	pass # Replace with function body.


func _on_GraphEdit_popup_request(position):
	var p = $GraphEdit/PopupMenu
	p.show()
	p.set_position(position)
	pass # Replace with function body.


func _on_GraphEdit_gui_input(event):
	if event is InputEventMouseMotion:
		$GraphEdit/PopupMenu.hide()
	pass # Replace with function body.


func _on_PopupMenu_id_pressed(ID):
	current_node = ID
	pass # Replace with function body.
