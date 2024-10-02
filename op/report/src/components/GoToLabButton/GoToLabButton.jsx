import { Link, useLocation } from "react-router-dom";

export default function GoToLabButton() {
  const location = useLocation();

  function handleGoToLab() {
    const pathParts = location.pathname.split("/");

    if (pathParts.length > 1) {
      const basePath = pathParts[1];

      return `/${basePath}`;
    }
  }

  return (
    <Link to={handleGoToLab()} className="text-gray-400 py-2 z-1 relative">
      &lt; Повернутися до каталогу
    </Link>
  );
}
