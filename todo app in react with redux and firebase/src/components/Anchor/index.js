import { Link } from "react-router-dom";

export default function Anchor({link, text, style}){
    return(
        <Link className={style} to={link}>{text}</Link>
    )
}