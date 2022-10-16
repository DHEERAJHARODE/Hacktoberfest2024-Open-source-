import { initializeApp } from "firebase/app";
import { getDatabase, set, ref, child, get, push, remove } from 'firebase/database';
import { getAuth, createUserWithEmailAndPassword, signInWithEmailAndPassword, onAuthStateChanged, signOut } from 'firebase/auth';
const firebaseConfig = {
    apiKey: "",
    authDomain: "",
    projectId: "",
    storageBucket: "",
    messagingSenderId: "",
    appId: ""
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth();
const db = getDatabase();

export {
    db,
    auth,
    createUserWithEmailAndPassword,
    signInWithEmailAndPassword,
    set,
    ref,
    child,
    get,
    push,
    onAuthStateChanged,
    signOut,
    remove
}