extends Node2D

var node = load("res://node.tscn")

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


func _on_Button_pressed():
	var newNode = node.instance()
	$GraphEdit.add_child(newNode)
	pass # Replace with function body.
