const fs = require("fs");
const path = require("path");
const process = require("process");

const RYU_WASM_INDEX_PATH = path.join(__dirname, "node_modules", "ryugraph-wasm", "index.js");
const RYU_WASM_WORKER_PATH = path.join(__dirname, "node_modules", "ryugraph-wasm", "ryugraph_wasm_worker.js");
const DESTINATION_PATH = path.join(__dirname, "public");

if (!fs.existsSync(RYU_WASM_INDEX_PATH) || !fs.existsSync(RYU_WASM_WORKER_PATH)) {
    console.log("RyuGraph WebAssembly module not found. Please run `npm i` to install the dependencies.");
    process.exit(1);
}

console.log("Copying RyuGraph WebAssembly module to public directory...");
console.log(`Copying ${RYU_WASM_INDEX_PATH} to ${DESTINATION_PATH}...`);
fs.copyFileSync(RYU_WASM_INDEX_PATH, path.join(DESTINATION_PATH, "index.js"));
console.log(`Copying ${RYU_WASM_WORKER_PATH} to ${DESTINATION_PATH}...`);
fs.copyFileSync(RYU_WASM_WORKER_PATH, path.join(DESTINATION_PATH, "ryugraph_wasm_worker.js"));
console.log("Done.");
