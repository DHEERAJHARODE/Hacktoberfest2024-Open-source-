// Basic setup for the grid
const gridContainer = document.getElementById('grid');
const rows = 20;
const cols = 20;
let startNode = null;
let endNode = null;
let isRunning = false;

const grid = [];

// Initialize grid
for (let r = 0; r < rows; r++) {
    const row = [];
    for (let c = 0; c < cols; c++) {
        const cell = document.createElement('div');
        gridContainer.appendChild(cell);
        const node = {
            element: cell,
            row: r,
            col: c,
            isWall: false,
            g: Infinity,
            h: Infinity,
            f: Infinity,
            parent: null
        };
        row.push(node);

        // Add event listeners to make cells interactive
        cell.addEventListener('click', () => {
            if (!startNode) {
                startNode = node;
                node.element.classList.add('start');
            } else if (!endNode) {
                endNode = node;
                node.element.classList.add('end');
            } else {
                node.isWall = !node.isWall;
                node.element.classList.toggle('wall');
            }
        });
    }
    grid.push(row);
}

// Heuristic function (Manhattan distance)
function heuristic(nodeA, nodeB) {
    return Math.abs(nodeA.row - nodeB.row) + Math.abs(nodeA.col - nodeB.col);
}

// A* Algorithm
async function aStar() {
    if (!startNode || !endNode) return alert("Please select start and end nodes.");

    isRunning = true;

    // Initialize open and closed lists
    const openList = [startNode];
    const closedList = [];

    startNode.g = 0;
    startNode.h = heuristic(startNode, endNode);
    startNode.f = startNode.h;

    while (openList.length > 0) {
        // Sort openList by f value
        openList.sort((a, b) => a.f - b.f);
        const currentNode = openList.shift();

        if (currentNode === endNode) {
            await drawPath(currentNode);
            isRunning = false;
            return;
        }

        closedList.push(currentNode);
        currentNode.element.classList.add('closed');

        // Explore neighbors
        const neighbors = getNeighbors(currentNode);
        for (const neighbor of neighbors) {
            if (closedList.includes(neighbor) || neighbor.isWall) continue;

            const tentativeG = currentNode.g + 1;
            if (tentativeG < neighbor.g) {
                neighbor.g = tentativeG;
                neighbor.h = heuristic(neighbor, endNode);
                neighbor.f = neighbor.g + neighbor.h;
                neighbor.parent = currentNode;

                if (!openList.includes(neighbor)) {
                    openList.push(neighbor);
                    neighbor.element.classList.add('open');
                }
            }
        }
        await sleep(50);  // Control speed
    }
    alert("No path found");
    isRunning = false;
}

// Function to draw the final path
async function drawPath(node) {
    while (node.parent) {
        node = node.parent;
        node.element.classList.add('path');
        await sleep(50);
    }
}

// Get neighbors of a node
function getNeighbors(node) {
    const neighbors = [];
    const { row, col } = node;
    if (row > 0) neighbors.push(grid[row - 1][col]); // Up
    if (row < rows - 1) neighbors.push(grid[row + 1][col]); // Down
    if (col > 0) neighbors.push(grid[row][col - 1]); // Left
    if (col < cols - 1) neighbors.push(grid[row][col + 1]); // Right
    return neighbors;
}

// Sleep function to slow down visualization
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Reset grid
function resetGrid() {
    grid.forEach(row => row.forEach(cell => {
        cell.element.className = '';
        cell.isWall = false;
        cell.g = Infinity;
        cell.h = Infinity;
        cell.f = Infinity;
        cell.parent = null;
    }));
    startNode = null;
    endNode = null;
}

// Event listeners
document.getElementById('startBtn').addEventListener('click', () => {
    if (!isRunning) aStar();
});

document.getElementById('resetBtn').addEventListener('click', resetGrid);
