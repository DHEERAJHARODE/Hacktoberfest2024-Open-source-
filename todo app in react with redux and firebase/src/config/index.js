import AppRouter from "./Router";
import {
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
} from './Firebase'
export {
    AppRouter,
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