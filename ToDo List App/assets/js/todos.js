//Check off Specific Todos by Clicking
//HARD WAY
/*$("li").click(function(){
	//if li is grey
	if($(this).css("color") === "rgb(128, 128, 128)"){
	//turn it black
		$(this).css({
			color: "black",
			textDecoration: "none"
		});	
	}
	//else
	else {		
	//turn it grey
		$(this).css({
			color: "grey",
			textDecoration: "line-through"
		});		
	}
});*/

//EASY WAY
$("ul").on("click", "li", function(){
	$(this).toggleClass("completed");
});

//Click on X to delete Todo
$("ul").on("click", "span", function(event){
	$(this).parent().fadeOut(500, function(){
		$(this).remove();
	});
	event.stopPropagation();
});

//Creating new Todo
$("input[type='text']").keypress(function(event){
	if(event.which === 13){
		//grabbing new todo text from input
		var newTodoText = $(this).val();
		$(this).val("");
		//create a new li and add to ul
		$("ul").append("<li><span><i class='fas fa-minus-square'></i></span> " + newTodoText + "</li>")
	}
});

//toggle add new todo form
$(".fa-plus-square").click(function(){
	$("input[type='text']").fadeToggle();
})