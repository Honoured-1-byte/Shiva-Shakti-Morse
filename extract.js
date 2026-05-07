const fs = require('fs');
const path = require('path');

const folders = [
    'Rigveda', 'Yajurveda', 'Atharvaveda', 
    'SrimadBhagvadGita', 'ValmikiRamayana', 'Ramcharitmanas', 'Mahabharata'
];

let masterText = "";
let totalVerses = 0;

console.log("Starting deep extraction...");

// Recursive function to hunt down the text strings no matter how deep they are nested
function extractText(obj) {
    if (!obj) return;

    if (Array.isArray(obj)) {
        // If it's an array, iterate through its items
        obj.forEach(item => extractText(item));
    } else if (typeof obj === 'object') {
        // If it's an object, check if it has our target keys
        // We look for 'text', 'content', or 'shloka' just to be safe
        if (obj.text) {
            masterText += obj.text + "\n";
            totalVerses++;
        } else if (obj.content) {
            masterText += obj.content + "\n";
            totalVerses++;
        } else if (obj.shloka) {
            masterText += obj.shloka + "\n";
            totalVerses++;
        } else {
            // If the keys aren't at this level, dive deeper into the object's values
            Object.values(obj).forEach(val => extractText(val));
        }
    }
}

folders.forEach(folder => {
    const folderPath = path.join(__dirname, folder);
    
    if (fs.existsSync(folderPath)) {
        const files = fs.readdirSync(folderPath).filter(file => file.endsWith('.json'));

        files.forEach(file => {
            try {
                const rawData = fs.readFileSync(path.join(folderPath, file));
                const jsonData = JSON.parse(rawData);
                
                // Pass the parsed JSON to our recursive hunter
                extractText(jsonData);
                
            } catch (error) {
                console.error(`Failed to parse ${file}: ${error.message}`);
            }
        });
        console.log(`Processed ${folder}`);
    }
});

// Write the massive combined string to a single text file
fs.writeFileSync('master_devanagari_corpus.txt', masterText);

console.log(`\nSuccess! Extracted ${totalVerses} total verses.`);
console.log("Saved to: master_devanagari_corpus.txt");