function updateContent(newState) {
    var mainContent = document.getElementById("state-content");
    var routeName = "/get_content/" + newState;
    
    // Load content from the corresponding route using AJAX
    fetch(routeName)
        .then(response => response.text())
        .then(data => {
            mainContent.innerHTML = data;
        })
        .catch(error => {
            console.error('Error fetching content:', error);
        });
}

// Function to update content based on the current state
function updateBasedOnState() {
    var currentState = "{{ state }}";
    updateContent(currentState);
}

// Call the initial content update
updateBasedOnState();

// Periodically check for state updates and update content
setInterval(updateBasedOnState, 1000); // Adjust the interval as needed
