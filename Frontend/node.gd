extends GraphNode

const SPRITE = 0
const ASPRITE = 1
const RULE = 2
const LAYER = 3
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


func _on_GraphNode_close_request():
	queue_free()
	pass # Replace with function body.

