extends GraphNode

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


func _on_GraphNode_close_request():
	queue_free()
	pass # Replace with function body.


func _on_GraphNode_resize_request(new_minsize):
	rect_size = new_minsize
	pass # Replace with function body.
